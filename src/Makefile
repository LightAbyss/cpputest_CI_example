OUT=out_sw

OBJDIR= build/

SRC = functions.c main.c
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(OBJDIR) $(OUT)
$(OUT): $(OBJ)
	gcc $^ -o $@

$(OBJDIR)%.o: %.c
	$(CC) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR) $(OUT)