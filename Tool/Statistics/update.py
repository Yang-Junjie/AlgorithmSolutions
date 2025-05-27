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
        plt.plot(dates, data, 
                marker=markers[idx%5], 
                linewidth=2,  # 增加线宽提高可视性
                markersize=5, # 增大标记尺寸
                label=f"{platform} ({data[-1]})" if data else platform)

    # 坐标轴优化
    ax = plt.gca()
    ax.xaxis.set_major_formatter(mdates.DateFormatter('%m-%d'))  # 保持日期格式
    
    # 动态设置x轴刻度（核心修改部分）
    if dates:
        # 生成基础索引（每隔7天）
        indices = list(range(0, len(dates), 7))
        # 强制包含最后一个数据点
        if not indices or indices[-1] != len(dates)-1:
            indices.append(len(dates)-1)
        selected_dates = [dates[i] for i in indices]
        ax.set_xticks(selected_dates)
    
    # 美化设置
    ax.grid(True, linestyle='--', alpha=0.7)  # 虚线网格
    plt.gcf().autofmt_xdate()  # 自动旋转日期标签
    
    # 添加数据标签（可选增强）
    for platform, data in platforms.items():
        last_point = (dates[-1], data[-1])
        plt.annotate(f'{last_point[1]}', 
                     xy=last_point,
                     xytext=(5, 0), 
                     textcoords='offset points',
                     ha='left')

    # 输出保存
    plt.title(f"The trend of doing practice questions on the OJ platform(Total Solved:{sum(data[-1] for data in platforms.values())})", 
             fontsize=14, pad=20)  # 增加标题间距
    plt.xlabel('Date', labelpad=10)
    plt.ylabel('Number', labelpad=10)
    plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')  # 优化图例位置
    plt.tight_layout()
    
    # 保存高清图像
    plt.savefig(os.path.join(img_dir, 'activity.png'), dpi=300, bbox_inches='tight')
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
    print("记录已更新")