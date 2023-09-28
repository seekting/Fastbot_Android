#文章来源：https://github.com/5ec1cff/my-notes/blob/master/debug-app-process.md
export pkg=com.smile.gifmaker
function build(){
./gradlew  makeJar
~/Library/Android/sdk/build-tools/28.0.3/dx --dex --output=monkeyq.jar monkey/build/libs/monkey.jar
adb push *.jar /sdcard
}
function monkey(){
adb  shell CLASSPATH=/sdcard/monkeyq.jar:/sdcard/framework.jar:/sdcard/fastbot-thirdpart.jar exec app_process /system/bin com.android.commands.monkey.Monkey -p $pkg --agent reuseq --running-minutes 30 --throttle 500 -v -v
}
function debug(){
#adb  shell CLASSPATH=/sdcard/monkeyq.jar:/sdcard/framework.jar:/sdcard/fastbot-thirdpart.jar exec app_process -Ddebuggable=true /system/bin com.android.commands.monkey.Monkey -p $pkg --wait-dbg  --agent reuseq --running-minutes 30 --throttle 500 -v -v
#adb forward tcp:5005 tcp:5005
adb shell CLASSPATH=/sdcard/monkeyq.jar:/sdcard/framework.jar:/sdcard/fastbot-thirdpart.jar exec app_process -XjdwpProvider:adbconnection -XjdwpOptions:suspend=n,server=y -Xcompiler-option --debuggable /system/bin com.android.commands.monkey.Monkey -p $pkg --wait-dbg --agent reuseq --running-minutes 30 --throttle 500 -v -vadb shell CLASSPATH=/sdcard/monkeyq.jar:/sdcard/framework.jar:/sdcard/fastbot-thirdpart.jar exec app_process -XjdwpProvider:adbconnection -Xcompiler-option --debuggable -XjdwpOptions:transport=dt_socket -XjdwpOptions:suspend=n,server=y,address=8888 /system/bin com.android.commands.monkey.Monkey -p $pkg --wait-dbg --agent reuseq --running-minutes 30 --throttle 500 -v -v

}