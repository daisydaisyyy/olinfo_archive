PDFLATEX=pdflatex -shell-escape

all:
	-rm comprog.pdf
	-rm -r _src/
	cp -r src/ _src/
	clang-format -i _src/*.?pp
	clang-format -i _src/**/*.?pp
	python preprocess.py
	python gen.py > gen.tex
	$(PDFLATEX) comprog
	$(PDFLATEX) comprog
	$(PDFLATEX) comprog
	rm -f *.aux *.log *.toc *.fls *.fdb_latexmk
	rm -rf _src/


BUILD_DIR = build
TEST_DIR = tests
SRC_DIR = src
TEST_SOURCES = $(shell find $(TEST_DIR)/ -name "*.cpp")
SOURCES = $(shell find $(SRC_DIR)/ -name "*.?pp")
OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.o)

test: $(OBJECTS)
	@for t in $^; do ./$$t; done;

.SECONDEXPANSION:

$(OBJECTS) : $$(patsubst $(BUILD_DIR)/%.o,$(TEST_DIR)/%.cpp,$$@) $(SOURCES)
	@mkdir -p $(@D)
	g++ -std=c++14 -I src/ -o $@ $<

clean:
	$(RM) comprog.pdf
	$(RM) -r build/
	$(RM) comprog.aux
	$(RM) comprog.toc

