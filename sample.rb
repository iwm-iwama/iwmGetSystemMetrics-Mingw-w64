#!ruby
#coding:utf-8

# https://learn.microsoft.com/ja-jp/windows/win32/api/winuser/nf-winuser-getsystemmetrics
aSM = ["SM_CXSCREEN", "SM_CYSCREEN"]
W, H = aSM

hSM = {}

%x(iwmGetSystemMetrics.exe -id=#{aSM.join(",")})
.each_line do |_s1|
	_key, _value, _exp = _s1.strip.split("\t")
	hSM[_key] = _value
end

p hSM
print W, " = ", hSM[W], "\n"
print H, " = ", hSM[H], "\n"
