# windows
重写WindowImplBase类中GetSkinFile 把绘制的界面文件xml文件引入，GetWindowClassName重定义窗口类名称重写WindowImplBase类中的消息响应函数Notify对于鼠标点击界面中的各个控件进行响应，
在重写notyfy函数进行响应现对界面产生的消息进行判断，msg.pSender->GetName();获取控件名称，
m_PaintManager.FindControl获取想要的控件
用图片生产动态图

使用图片生成gif ffmpeg -r 3 -i .\Pictrue\%d.jpg output.gif -y -r 控制帧数

用视频生产动态图
 
ffmpeg -i 33.mkv -s 200*200 -r 15 output.gif -y 
-s: 图片大小 ffmpeg -i 33.mkv -vf scale=iw/2:ih/2 -f gif output.gif -y 将视频按照等比例缩小后，生成gif

 一个视频文件：视频流 音频流 字幕流

1.从原视频截取片段
ffmpeg -i input.mkv -vcodec copy -acodec copy -ss 00:40:07 -to 00:40:28 11.mkv -y 
-i 输入 
11.mkv 需要截取视频的路径 
-vcode copy -acode copy 表示所要使用的视频和音频的编码格式，
copy表示原样拷贝 -ss 00:40:07 代表起始时间 -to 00:40:28 代表结束时间 即总共截取了21秒 -y: 代表如果目录中有该文件，将源文件覆盖掉

2.从视频中提取字幕
ffmpeg -i 11.mkv input.srt -y

3.编辑视频中提取的字幕

4.从截取的小段视频中抽离视频流
ffmpeg -i 11.mkv -vcodec copy -an -sn 22.mkv -y -an: 表示取消音频 -sn: 表示取消字幕

5.将修改后的srt字幕 内嵌到视频中
ffmpeg -i 22.mkv -vf subtitles=11.srt 33.mkv -y

6.生成动态图
ffmpeg -i 33.mkv -s 200*200 -r 15 output.gif -y 
