all:	myls	mysearch	mystat	mytail
myls: myls-HuongDuong.c
	gcc	-o	myls	myls-HuongDuong.c
mysearch:	mysearch-HuongDuong.c
	gcc	-o	mysearch	mysearch-HuongDuong.c
mystat:	mystat-HuongDuong.c
	gcc	-o	mystat	mystat-HuongDuong.c
mytail:	mytail-HuongDuong.c
	gcc	-o	mytail	mytail-HuongDuong.c	