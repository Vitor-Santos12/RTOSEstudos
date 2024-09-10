# Nome do arquivo binário final
TARGET = meu_programa

# Compilador e flags
CC = g++
CFLAGS = -I./include -I./FreeRTOS/include -I./FreeRTOS/portable/GCC/Posix -Wall

# Diretórios de origem e destino
SRCDIR = src
OBJDIR = obj

# Lista de arquivos de código-fonte
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Regras
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) -lpthread

clean:
	rm -rf $(OBJDIR) $(TARGET)
