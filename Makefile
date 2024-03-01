CC = gcc
CFLAGS = -I$(INCLUDEDIR)
LDFLAGS = -L$(SRCDIR) -ldatastructures

SRCDIR = src/data_structures
INCLUDEDIR = ./include/ 
EXAMPLESDIR = examples/data_structures

EXAMPLE_SRCS = $(wildcard $(EXAMPLESDIR)/*.c)
EXAMPLE_OBJS = $(EXAMPLE_SRCS:$(EXAMPLESDIR)/%.c=%.o)

bear: $(SRCDIR)/slice.o

$(SRCDIR)/slice.o:
	bear -- $(CC) -c $(CFLAGS) -I$(INCLUDEDIR) -o $(SRCDIR)/slice.o $(SRCDIR)/slice.c

examples: $(EXAMPLE_OBJS) $(SRCDIR)/slice.o
	$(CC) -o $(EXAMPLE_OBJS:.o=.out) $(EXAMPLE_OBJS) $(SRCDIR)/slice.o $(LDFLAGS)

run-examples: examples
	@for example in $(EXAMPLE_OBJS); do \
		echo "Running $$example"; \
		./$${example%.o}.out; \
	done

clean:
	rm -f $(SRCDIR)/*.o $(EXAMPLESDIR)/*.o $(EXAMPLESDIR)/*.out
