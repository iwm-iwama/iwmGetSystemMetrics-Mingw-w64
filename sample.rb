#!ruby
#coding:utf-8

# https://learn.microsoft.com/ja-jp/windows/win32/api/winuser/nf-winuser-getsystemmetrics

# [KEY]を指定
SM = <<EOD
	SM_CXSCREEN
	SM_CYSCREEN
EOD

Key = SM.strip.gsub("\n", ",").gsub(/\s*/, "")

%x(iwmGetSystemMetrics.exe -key=#{Key})
.each_line do |_s1|
	_key, _value, _exp = _s1.strip.split("\t")
	# 存在チェック
	if _value
		# [KEY]を定数にして値を代入
		eval "#{_key} = #{_value}"
	end
end

print "SM_CXSCREEN", " = ", SM_CXSCREEN, "\n"
print "SM_CYSCREEN", " = ", SM_CYSCREEN, "\n"
