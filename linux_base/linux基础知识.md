# linux基础知识

1. 根目录：（/表示）——根文件系统
   1. bin（binary）：存放操作系统使用的命令
   1. sbin（super bin
   3. ）：存放超级用户使用命令
      1. 其中ifconfig：查看网卡信息
      1. reboot：重启
   3. dev（device）：存放设备文件
   3. etc：存放配置文件
      1. etc/passwd 保存所有用户
         1. etc/vimrc保存vim编辑器的配置 unbuntu：etc/vim/vimc)
      2. windows：目录\
         1. Linux:目录/
   5. home:存放家目录，用户对应一个同名目录，默认放在home下代码，一般日期/主题
   5. lib（library）：库文件
      1. .so动态库和.a静态库
      1. windows是.dll
   7. mnt(mount)：挂载点，目录挂载到磁盘某一个位置
   7. proc：查看进程信息
      1. 操作系统为应用层，linux内核不能被操作
      1. windows中exe一般一个进程，每个有编号：![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610678754228-6d90f8b4-bc43-48a3-a1ba-78af53c15385.png#align=left&display=inline&height=60&margin=%5Bobject%20Object%5D&name=image.png&originHeight=120&originWidth=517&size=39758&status=done&style=none&width=258.5)
   9. root：root用户的家目录
   9. sys（system）：查看或修改内核信息
   9. tmp：存放临时文件
   9. usr（user）：存放用户安装的软件![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610679441985-c9108b3a-e3ab-4762-bbed-5e5dd134a855.png#align=left&display=inline&height=83&margin=%5Bobject%20Object%5D&name=image.png&originHeight=165&originWidth=873&size=29312&status=done&style=none&width=436.5)
2. 路径
   1. ![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610681044342-c34fa1a4-348f-44ca-9bd5-410d65a2e0ad.png#align=left&display=inline&height=27&margin=%5Bobject%20Object%5D&name=image.png&originHeight=54&originWidth=412&size=9807&status=done&style=none&width=206)
      1. root用户名
      1. xyd-edu主机名（/etc/sysconfig/network）当前路径
         1. [如何修改主机名，hostname与hosts对应](https://www.cnblogs.com/kerrycode/p/3595724.html)
      3. #/$敲命令
      3. ~家目录
   2. 路径：
      1. 目录结构：![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610681539804-5b941958-20f3-469b-9ec0-436322f35422.png#align=left&display=inline&height=142&margin=%5Bobject%20Object%5D&name=image.png&originHeight=283&originWidth=840&size=14297&status=done&style=none&width=420)
      1. 绝对路径：根目录开始
         1. Ex：/为绝对路径
            1. /proc
            1. /home/111
            1. /usr/include/json
      3. 相对路径：相对当前位置路径
         1. cd：改变工作路径 从json到222
            1. cd /home/222 绝对路径
            1. cd ../../../home/222 相对路径
3. 命令：
   1. cd(change directory)
      1. cd.. ：进入上一级目录(linux..表示上一层目录)
      1. cd.：进入当前目录（linux中.表示当前目录）
      1. cd~：进入当前用户的 家目录（等价于cd 不加任何参数）
         1. root是root 普通用户在home下面
      4. cd -：进入上一次工作目录
      4. cd /：进入根目录
         1. ex：![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610682432557-76cdaa59-c489-4677-900b-0aa682c95067.png#align=left&display=inline&height=75&margin=%5Bobject%20Object%5D&name=image.png&originHeight=150&originWidth=548&size=20480&status=done&style=none&width=274)
      6. cd 绝对路径/相对路径
   2. ls：显示当前目录下的文件、文件夹
      1. ls -a
         1. .. 和 . 为隐藏文件
      2. ls +路径 ：显示指定路径下内容
      2. ls -l ：显示文件属性
         1. ![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610689205680-f9c3dc08-8491-4c55-b2be-90ee4e4e1531.png#align=left&display=inline&height=17&margin=%5Bobject%20Object%5D&name=image.png&originHeight=34&originWidth=665&size=4862&status=done&style=none&width=332.5)
            1. ![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610689392210-739a530f-57c1-44b1-a32c-d602c1373c16.png#align=left&display=inline&height=72&margin=%5Bobject%20Object%5D&name=image.png&originHeight=143&originWidth=404&size=15908&status=done&style=none&width=202)解释
         2. -rwx r-x r-x
            1. 文件属性：普通文件、目录文件、链接文件
               1. 链接文件：![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610689502520-472d0c9a-d429-43c1-9d81-77d26177ba65.png#align=left&display=inline&height=38&margin=%5Bobject%20Object%5D&name=image.png&originHeight=51&originWidth=623&size=13930&status=done&style=none&width=467)
            2. 当前用户权限：可读可写可执行rwx
            2. 同组其他用户
            2. 其他用户权限：可读可执行
4. 用户操作：添加删除用户修改密码
   1. 添加用户
      1. useradd name 
   2. 查看命令用法：
      1. useradd -help
      1. man 1 ls
   3. 查看用户
      1. /etc/passwd
      1. cat：显示内容
   4. 切换用户
      1. su name
   5. 删除用户
      1. userdel name
      1. 只删除用户，不删除家目录
      1. 用户与家目录关系
   6. root权限：添加/删除只能在root，不然![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610691863152-d8873ff2-5bfb-49a8-8283-456289ea6fec.png#align=left&display=inline&height=55&margin=%5Bobject%20Object%5D&name=image.png&originHeight=110&originWidth=450&size=12310&status=done&style=none&width=225)
5. 文件与文件夹
   1. touch 文件
   1. mkdir 文件夹
   1. 删除
      1. rm
      1. rm -rf aa*
         1. -r：递归，遍历下去
         1. -f：强制force
         1. 删除以aa开头的所有文件
6. 拷贝与剪切
   1. cp拷贝文件
      1.  文件在哪 拷贝到哪 （拷贝普通文件）
      1. cp /bin/ls . 将bin下所有拷贝到当前目录
   2. 拷贝目录
      1. cp -r  文件在哪 拷贝到哪
      1. cp -r /usr/local/include/ .
   3. 剪切文件 mv
      1. mv ls /tmp
7. 改变文件权限
   1. 引出：![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610694159317-d942d18e-7373-42df-a323-8908298852b0.png#align=left&display=inline&height=178&margin=%5Bobject%20Object%5D&name=image.png&originHeight=237&originWidth=678&size=24958&status=done&style=none&width=509)
   1. 第一列—：表示属性
   1. 用二进制改：chmod 755 aaa
      1. ![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610693913601-4bc42e5a-d85b-4ada-b80a-5367b3ae1d04.png#align=left&display=inline&height=75&margin=%5Bobject%20Object%5D&name=image.png&originHeight=150&originWidth=397&size=21836&status=done&style=none&width=198.5)
      1. ![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610693804075-42742fcc-4de2-491b-bed6-888766ad55d6.png#align=left&display=inline&height=53&margin=%5Bobject%20Object%5D&name=image.png&originHeight=53&originWidth=132&size=2787&status=done&style=none&width=132)有为1，无0 644
      1. r为4，w为2，x为1
   4. 用chmod u|g|o +/- r|w|x aaa ？？
      1. u g o 
8. 压缩与解压操作
   1. 打包：
      1. tar -zcf+压缩名+文件1 文件2
      1. z是zip压缩
   2. 解压
      1. tar -x任意（v）f 
      1. x是解压
   3. 参考：
      1. ![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610941005004-ef2c0ad9-4d40-478f-ac97-af25356d5e3d.png#align=left&display=inline&height=128&margin=%5Bobject%20Object%5D&name=image.png&originHeight=255&originWidth=714&size=27961&status=done&style=none&width=357)
9. 空间产生非空文件
   1. dd：产生非空文件，全部为0
      1. ![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610696077441-1ce998ef-1870-4226-84c0-27199ec541c3.png#align=left&display=inline&height=56&margin=%5Bobject%20Object%5D&name=image.png&originHeight=112&originWidth=530&size=17362&status=done&style=none&width=265)
      1. dd if=/dev/zero of=testfile bs=1M count=16
         1. count是大小 bs表示以块为单位blocksize 1m生成
   2. 查看文件大小
      1. du -sm du -sk
10. 查找文件与搜索字符串
   1. find 路径 -name 文件名
      1. find /（根目录） -name "jianhong"
   2. grep搜文件中的字符
      1. grep "jianhong" /etc/* -r
         1. -r遍历
      2. cat /etc/passwd | grep home
         1. |是管道，排除其他影响的
   3. | 利用它 ：| grep xx
      1. Ex输出结果进行搜索：![image.png](https://cdn.nlark.com/yuque/0/2021/png/1689647/1610698129641-821f8eff-7f8f-4847-9299-90fecf7d5545.png#align=left&display=inline&height=154&margin=%5Bobject%20Object%5D&name=image.png&originHeight=206&originWidth=355&size=26293&status=done&style=none&width=266)
         1. ps-elf 查看当前所有进程



