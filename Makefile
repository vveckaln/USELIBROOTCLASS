CC_FILES      := $(wildcard *.cc)
BINS          := $(CC_FILES:.cc=)

all:$(BINS)


%: %.cc 
	g++ -g `root-config --cflags --glibs` -I${PRIVATE}/LIBPROJROOTCLASS/interface  -L${PRIVATE}/LIBPROJROOTCLASS/lib -lrootclasstest  -Wl,-rpath,${PRIVATE}/LIBPROJROOTCLASS/lib  $^ -o $@

.PHONY: clean
clean:
	find . -maxdepth 1 -type f -perm +a=x -print0 | xargs -0 -I {} rm {}
