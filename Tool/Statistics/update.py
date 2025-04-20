import os
import csv
from datetime import datetime
from matplotlib import pyplot as plt
import matplotlib.dates as mdates
import numpy as np
from collections import defaultdict


# ----------------- 全局路径配置 -----------------
script_dir = os.path.dirname(os.path.abspath(__file__))  # 脚本绝对路径[9](@ref)
config_dir = os.path.join(script_dir, "config")          # 配置文件目录
data_dir = os.path.join(script_dir, "data")              # 数据存储目录
img_dir = os.path.join(script_dir, "images")             # 图片输出目录
base_dir = os.path.normpath(os.path.join(script_dir, "../../"))  # 项目根目录

# 创建必要目录
os.makedirs(config_dir, exist_ok=True)
os.makedirs(data_dir, exist_ok=True)
os.makedirs(img_dir, exist_ok=True)

# ----------------- 数据采集模块 -----------------
def read_directories_from_file(file_path=None):
   
    target_path = file_path or os.path.join(config_dir, "OJLists.txt")  # 自动定位配置文件[8](@ref)
    try:
        with open(target_path, 'r', encoding='utf-8') as f:
            return [d.strip() for d in f.read().split(',') if d.strip()]
    except Exception as e:
        print(f"配置读取失败：{e}")
        return []

def count_main_cpp(directory):
    
    abs_dir = os.path.abspath(directory)
    return sum(1 for root, _, files in os.walk(abs_dir) if "main.cpp" in files)

def update_csv(data, csv_path=None):
    csv_path = csv_path or os.path.join(data_dir, "cpp_stats.csv")
    today = datetime.now().strftime('%Y-%m-%d')
    fieldnames = ["日期"] + list(data.keys())

    # 读取/更新数据
    existing_data = []
    if os.path.exists(csv_path):
        with open(csv_path, 'r', encoding='utf-8') as f:
            reader = csv.DictReader(f)
            existing_data = list(reader)

    # 更新当天数据
    found = False
    for row in existing_data:
        if datetime.strptime(row["日期"], "%Y-%m-%d").date() == datetime.today().date():
            row.update(data)
            found = True
            break
    if not found:
        existing_data.append({"日期": today, **data})

    # 写入文件
    with open(csv_path, 'w', encoding='utf-8', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(sorted(existing_data, 
            key=lambda x: datetime.strptime(x["日期"], "%Y-%m-%d")))

# ----------------- 可视化模块 ------------------
def plot_activity(csv_path=None):
    """绘制活动趋势图（动态路径处理）"""
    csv_path = csv_path or os.path.join(data_dir, "cpp_stats.csv")
    
    dates, platforms = [], {}
    with open(csv_path, 'r', encoding='utf-8') as f:
        reader = csv.DictReader(f)
        for row in reader:
            dates.append(datetime.strptime(row["日期"], '%Y-%m-%d'))
            for platform in reader.fieldnames[1:]:
                platforms.setdefault(platform, []).append(int(row[platform]))

    # 绘图配置
    plt.figure(figsize=(12, 7))
    markers = ['o', 's', '^', 'd', '*']
    for idx, (platform, data) in enumerate(platforms.items()):
        # 修改label格式，添加最新数值[14](@ref)
        plt.plot(dates, data, 
                marker=markers[idx%5], 
                label=f"{platform} ({data[-1]})" if data else platform)

    # 坐标轴优化
    ax = plt.gca()
    ax.xaxis.set_major_formatter(mdates.DateFormatter('%m-%d'))
    ax.set_xticks(dates)
    ax.grid(True)
    plt.gcf().autofmt_xdate()
    
    # 输出保存
    plt.title("The trend of doing practice questions on the OJ platform", fontsize=14)
    plt.xlabel('Date')
    plt.ylabel('Number')
    plt.legend(bbox_to_anchor=(1.05, 1))
    plt.tight_layout()
    plt.savefig(os.path.join(img_dir, 'activity.png'))



# ... (保持原有路径配置和数据采集模块不变) ...

# ----------------- 修改后的可视化模块 -----------------
def calculate_deltas(data_list):
    """计算相邻数据点之间的差值"""
    deltas = [0]  # 第一个数据点没有变化量
    for i in range(1, len(data_list)):
        deltas.append(data_list[i] - data_list[i-1])
    return deltas

def plot_platform_deltas(csv_path=None):
    """生成每个平台的差值变化图"""
    csv_path = csv_path or os.path.join(data_dir, "cpp_stats.csv")
    
    # 数据存储结构
    platform_data = defaultdict(lambda: {
        'daily': {'dates': [], 'counts': []},
        'monthly': {'months': [], 'counts': []}
    })

    # 处理原始数据
    with open(csv_path, 'r', encoding='utf-8') as f:
        reader = csv.DictReader(f)
        platforms = reader.fieldnames[1:]
        
        for row in reader:
            date = datetime.strptime(row["日期"], "%Y-%m-%d")
            month = date.strftime("%Y-%m")
            
            for platform in platforms:
                # 记录日维度原始数据
                data = platform_data[platform]
                data['daily']['dates'].append(date)
                data['daily']['counts'].append(int(row[platform]))
                
                # 记录月维度原始数据（先累积）
                if month not in data['monthly']['months']:
                    data['monthly']['months'].append(month)
                    data['monthly']['counts'].append(0)
                month_idx = data['monthly']['months'].index(month)
                data['monthly']['counts'][month_idx] += int(row[platform])

    # 为每个平台生成图表
    for platform, data in platform_data.items():
        # 计算差值
        daily_deltas = calculate_deltas(data['daily']['counts'])  # 日变化量
        monthly_counts = data['monthly']['counts']
        monthly_deltas = calculate_deltas(monthly_counts)  # 月变化量
        
        # 创建画布
        plt.figure(figsize=(14, 6))
        
        # ---------- 左图：月差值变化 ----------
        ax1 = plt.subplot(1, 2, 1)
        months = data['monthly']['months'][1:]  # 排除第一个月（没有变化量）
        
        # 使用双色区分增/减
        colors = ['#2ca02c' if d >=0 else '#d62728' for d in monthly_deltas[1:]]
        bars = ax1.bar(months, monthly_deltas[1:], color=colors, alpha=0.7)
        
        # 添加数值标签
        for bar in bars:
            height = bar.get_height()
            ax1.text(bar.get_x() + bar.get_width()/2., height,
                    f'{height:+}', ha='center', va='bottom')
        
        ax1.set_title(f"Monthly Changes - {platform}")
        ax1.set_ylabel("Δ Submissions")
        ax1.grid(axis='y', alpha=0.3)
        
        # ---------- 右图：日差值变化 ----------
        ax2 = plt.subplot(1, 2, 2)
        recent_dates = [d.strftime("%m-%d") for d in data['daily']['dates'][-7:]]
        recent_deltas = daily_deltas[-7:]
        
        # 添加趋势线
        ax2.plot(recent_dates, recent_deltas, 'b--', alpha=0.5, label='Trend')
        bars_daily = ax2.bar(recent_dates, recent_deltas, 
                           color=np.where(np.array(recent_deltas)>=0, '#1f77b4', '#ff7f0e'),
                           alpha=0.7)
        
        # 显示特殊数据点
        for bar in bars_daily:
            height = bar.get_height()
            if abs(height) > (max(recent_deltas)*0.5):  # 标记显著变化
                ax2.text(bar.get_x() + bar.get_width()/2., height,
                        f'{height}', ha='center', va='bottom',
                        fontweight='bold')
        
        ax2.set_title(f"Daily Changes - {platform}")
        ax2.set_ylabel("Δ Submissions")
        ax2.legend()
        ax2.grid(axis='y', alpha=0.3)
        
        # 优化布局
        plt.tight_layout()
        
        # 保存图表
        safe_name = platform.replace(" ", "_").replace("/", "-")
        plt.savefig(os.path.join(img_dir, f"{safe_name}_deltas.png"), dpi=150)
        plt.close()
        

# ----------------- 主流程 -----------------
if __name__ == "__main__":
    # 动态路径处理
    directories = read_directories_from_file()
    if not directories:
        print("无有效目录，请检查 config/OJLists.txt")
        exit()

    stats = {
        dir_name: count_main_cpp(os.path.join(base_dir, dir_name)) 
        for dir_name in directories
    }
    update_csv(stats)
    plot_activity()
    plot_platform_deltas()
    print("记录已更新")