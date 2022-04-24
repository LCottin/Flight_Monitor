#-----------------------------------------#
#			COMPILER OPTIONS			  #
#-----------------------------------------#
CX		 = g++
CXFLAGS  = -std=c++17 -Wall -Wextra
EXT		 = cpp
LIBS	 = -lsfml-graphics -lsfml-system -lsfml-window -lm
DIR_OBJS = ./bin
INCLUDE  = -I./include/ -I./SFML/
EXEC	 = $(DIR_OBJS)/main

#-----------------------------------------#
#				FILES    				  #
#-----------------------------------------#
SRC := $(shell echo src/*.$(EXT))

#notdir    : returns the file only without its folder (src/main.c 	 -> main.c)
#basename  : returns the file withtout its suffix     (main.c     	 -> main)
#addprefix : returns the file with its new prefix     (main 	  	 -> DIR_OBJS/main)
#addsuffix : returns the file with its new suffix     (DIR_OBJS/main -> DIR_OBJS/main.o)
OBJS = $(addsuffix .o, $(addprefix $(DIR_OBJS)/, $(basename $(notdir $(SRC)))))

#-----------------------------------------#
#	       	COMPILING RULES	      		  #
#-----------------------------------------#
all: build $(OBJS) 
	$(CX) $(CXFLAGS) $(OBJS) -o $(EXEC) $(LIBS) $(INCLUDE)
	@echo Project compiled !

# Builds .o's from .cpp's using automatic variables 
#	$<: the name of the prerequisite of the rule -> .cpp file 
#	$@: the name of the target of the rule 		 -> .o file
$(DIR_OBJS)/%.o : ./src/%.$(EXT)
	$(CX) $(CXFLAGS) -c $< -o $@ $(INCLUDE)

.PHONY: build # To avoid errors when building 
build:
	mkdir -p $(DIR_OBJS)

.PHONY: clean # To avoid errors when cleaning
clean:
	rm -rf $(DIR_OBJS)
	@echo Files deleted, project clean.