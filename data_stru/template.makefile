#**
#* makefile模板文件
#* 你需要先定义SRC,EXEC变量的值，然后include本文件
#* 在SRC中不必包含主函数文件
#***
CC		:=	g++
FLAGS	:=	-g
OBJ		:=	$(SRC:.cc=.o)

all:	$(EXEC)

$(EXEC): $(OBJ) $(EXEC).cc
	$(CC) $(FLAGS) -o $@ $(OBJ) $(EXEC).cc

clean:
	rm $(OBJ) $(EXEC)