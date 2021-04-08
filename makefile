EXT= c
CXX= gcc

EXEC= main
CXX_FLAGS= -Wall -Wno-deprecated-declarations
LDFLAGS= -lGL -lGLU -lglut -lm

OBJ_DIR = obj
SRC = $(wildcard *.$(EXT))
OBJ = $(SRC:.$(EXT)=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))

all: setup $(EXEC)

setup:
	mkdir -p obj

$(EXEC): $(OBJ)
	@$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: %.$(EXT)
	@$(CXX) -o $@ -c $< $(CXX_FLAGS)

clean:
	rm -f $(EXEC)
	rm -rf obj
