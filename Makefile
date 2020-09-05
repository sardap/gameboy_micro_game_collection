ROM_NAME = micro_games.gb
CLEAN = 1

build:
	@mkdir -p bin/
	@cd src/ && \
		make all && \
		mv main.gb ../bin/$(ROM_NAME) && \
		make clean

clean:
	rm -rf bin/