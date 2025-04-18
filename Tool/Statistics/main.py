import os
import sys

# ------------ 全局配置 ------------
script_dir = os.path.dirname(os.path.abspath(__file__))
base_dir = os.path.normpath(os.path.join(script_dir, "../../"))
config_dir = os.path.join(script_dir, "config")
os.makedirs(config_dir, exist_ok=True)

OJ_LIST_PATH = os.path.join(config_dir, "OJLists.txt")
CRATE_SH_PATH = os.path.join(script_dir, "crate.sh")

# ------------ 功能函数 ------------
def clear_screen():
    """清屏命令兼容不同系统"""
    os.system('cls' if os.name == 'nt' else 'clear')
def update_oj_list(oj_name):
    """更新逗号分隔的OJ列表文件"""
    try:
        # 读取现有内容
        if os.path.exists(OJ_LIST_PATH):
            with open(OJ_LIST_PATH, 'r', encoding='utf-8') as f:
                content = f.read().strip()
                existing = [x.strip() for x in content.split(',') if x.strip()]
        else:
            existing = []
        
        # 检查重复
        if oj_name in existing:
            print(f"[!] {oj_name} 已存在列表中")
            return False
        
        # 添加新条目
        existing.append(oj_name)
        
        # 写入文件（逗号分隔）
        with open(OJ_LIST_PATH, 'w', encoding='utf-8') as f:
            f.write(','.join(existing))
        
        print(f"[+] 已更新 {os.path.basename(OJ_LIST_PATH)}")
        return True
    except Exception as e:
        print(f"[!] 更新列表失败：{str(e)}")
        return False

def load_oj_list():
    """加载逗号分隔的OJ列表"""
    if not os.path.exists(OJ_LIST_PATH):
        return []
    
    with open(OJ_LIST_PATH, 'r', encoding='utf-8') as f:
        content = f.read().strip()
        return [x.strip() for x in content.split(',') if x.strip()]

def create_oj():
    """创建OJ目录（整合列表更新）"""
    while True:
        name = input("\n请输入OJ目录名称（q退出）: ").strip()
        if name.lower() == 'q':
            return
        
        # 合法性检查
        if not name.isalnum():
            print("[!] 名称只能包含字母和数字")
            continue
            
        target_dir = os.path.join(base_dir, name)
        
        # 目录存在性检查
        if os.path.exists(target_dir):
            print(f"[!] 目录已存在：{os.path.relpath(target_dir)}")
            continue
            
        try:
            # 创建目录
            os.makedirs(target_dir)
            print(f"[√] 目录创建成功：{name}")
            
            # 复制模板文件
            if os.path.exists(CRATE_SH_PATH):
                os.system(f"cp {CRATE_SH_PATH} {target_dir}")
                print(f"[√] 模板文件已复制")
            
            # 更新列表文件
            if update_oj_list(name):
                print(f"[√] 系统配置已更新")
            return
        except Exception as e:
            print(f"[!] 操作失败：{str(e)}")
            if os.path.exists(target_dir):
                os.rmdir(target_dir)

def view_statistics():
    """查看解题数据"""
    clear_screen()
    print("查看解题数据".center(40, '='))
    
    while True:
        name = input("\n请输入OJ目录名称（q退出）: ").strip().lower()
        if name == 'q':
            return
        
        target_dir = os.path.join(base_dir, name)
        
        if not os.path.exists(target_dir):
            print(f"[!] 目录不存在：{os.path.relpath(target_dir)}")
            continue
            
        # 统计解题数
        count = sum(1 for root, _, files in os.walk(target_dir) if "main.cpp" in files)
        print(f"\n{'-'*40}")
        print(f"OJ名称：{name}")
        print(f"解题总数：{count}")
        print(f"目录路径：{os.path.relpath(target_dir)}")
        print(f"{'-'*40}\n")

# ------------ 主界面 ------------
def main_menu():
    while True:
        clear_screen()
        print("\n" + "OJ管理系统".center(40, '='))
        print("1. 创建OJ目录")
        print("2. 查看解题数据")
        print("3. 退出系统")
        
        try:
            choice = input("\n请选择操作：").strip()
            if choice == '1':
                create_oj()
                input("\n按回车返回主菜单...")
            elif choice == '2':
                view_statistics()
                input("\n按回车返回主菜单...")
            elif choice == '3':
                print("\n感谢使用，再见！")
                sys.exit(0)
            else:
                print("[!] 无效输入，请重新选择")
        except KeyboardInterrupt:
            print("\n检测到强制退出，正在终止程序...")
            sys.exit(1)

if __name__ == "__main__":
    # 初始化必要文件
    if not os.path.exists(OJ_LIST_PATH):
        open(OJ_LIST_PATH, 'w').close()
    
    main_menu()