CC = gcc
CFLAGS = -I$(INCLUDEDIR)
LDFLAGS = -L$(SRCDIR) -ldatastructures

SRCDIR = src/data_structures
INCLUDEDIR = include/data_structures
EXAMPLESDIR = examples/data_structures

EXAMPLES = $(wildcard $(EXAMPLESDIR)/*.c)
OBJS = $(EXAMPLES:$(EXAMPLESDIR)/%.c=%.o)

bear: $(SRCDIR)/slice.o

$(SRCDIR)/slice.o:
	bear $(CC) -c $(CFLAGS) -o $(SRCDIR)/slice.o $(SRCDIR)/slice.c

examples: $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXAMPLESDIR)/%.out: $(EXAMPLESDIR)/%.o $(SRCDIR)/slice.o
	$(CC) -o $@ $< $(SRCDIR)/slice.o $(LDFLAGS)

run-examples: examples
	@for example in $(EXAMPLES); do \
		echo "Running $$example"; \
		./$${example%.c}.out; \
	done

clean:
	rm -f $(SRCDIR)/*.o $(EXAMPLESDIR)/*.o $(EXAMPLESDIR)/*.out
