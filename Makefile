#Set compiler
CXX = g++
CXXFLAGS = -Wall -pedantic -lSDL2 -std=c++14

#Set sources and object files
SOURCES = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.h)
OBJECTS = $(SOURCES:src/%.cpp = build/%.o)


.PHONY: all
all: compile doc

.PHONY: compile
compile: breakout

.PHONY: run
run: compile
	./breakout

.PHONY: clean
clean:
	rm -rf build/ doc/ breakout  2>/dev/null

breakout: build/main
	cp $< $@

doc: Doxyfile $(HEADERS)
	doxygen Doxyfile

build/main: $(OBJECTS)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $@

build/%.o: src/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $< -c -o $@

# Dependencies
#-------------------------------------------------------#

build/CApplication.o: src/CApplication.cpp src/CApplication.h src/CRenderer.h \
 src/CScoreBoard.h src/CLetter.h src/CObject.h src/CCoords.h src/CColor.h \
 src/CPaddle.h src/CLife.h src/CBrick.h src/CBall.h src/CGame.h \
 src/EGameState.h src/CInputManager.h src/CLevel.h src/CWidthModifier.h \
 src/CBaseModifier.h src/CLifeModifier.h src/CSpeedModifier.h \
 src/CBreakModifier.h src/CSplitModifier.h

build/CBall.o: src/CBall.cpp src/CBall.h src/CPaddle.h src/CObject.h \
 src/CCoords.h src/CColor.h src/CLife.h src/CBrick.h

build/CBaseModifier.o: src/CBaseModifier.cpp src/CBaseModifier.h src/CBall.h \
 src/CPaddle.h src/CObject.h src/CCoords.h src/CColor.h src/CLife.h \
 src/CBrick.h

build/CBreakModifier.o: src/CBreakModifier.cpp src/CBreakModifier.h \
 src/CBaseModifier.h src/CBall.h src/CPaddle.h src/CObject.h \
 src/CCoords.h src/CColor.h src/CLife.h src/CBrick.h

build/CBrick.o: src/CBrick.cpp src/CBrick.h src/CObject.h src/CCoords.h \
 src/CColor.h

build/CGame.o: src/CGame.cpp src/CGame.h src/EGameState.h src/CInputManager.h \
 src/CRenderer.h src/CScoreBoard.h src/CLetter.h src/CObject.h \
 src/CCoords.h src/CColor.h src/CPaddle.h src/CLife.h src/CBrick.h \
 src/CBall.h src/CLevel.h src/CWidthModifier.h src/CBaseModifier.h \
 src/CLifeModifier.h src/CSpeedModifier.h src/CBreakModifier.h \
 src/CSplitModifier.h

build/CInputManager.o: src/CInputManager.cpp src/CInputManager.h

build/CLetter.o: src/CLetter.cpp src/CLetter.h src/CObject.h src/CCoords.h \
 src/CColor.h

build/CLevel.o: src/CLevel.cpp src/CLevel.h src/CBrick.h src/CObject.h \
 src/CCoords.h src/CColor.h src/CRenderer.h src/CScoreBoard.h \
 src/CLetter.h src/CPaddle.h src/CLife.h src/CBall.h
build/CLife.o: src/CLife.cpp src/CLife.h src/CObject.h src/CCoords.h \
 src/CColor.h
build/CLifeModifier.o: src/CLifeModifier.cpp src/CLifeModifier.h \
 src/CBaseModifier.h src/CBall.h src/CPaddle.h src/CObject.h \
 src/CCoords.h src/CColor.h src/CLife.h src/CBrick.h
build/CObject.o: src/CObject.cpp src/CObject.h src/CCoords.h src/CColor.h
build/CPaddle.o: src/CPaddle.cpp src/CPaddle.h src/CObject.h src/CCoords.h \
 src/CColor.h src/CLife.h
build/CRenderer.o: src/CRenderer.cpp src/CRenderer.h src/CScoreBoard.h \
 src/CLetter.h src/CObject.h src/CCoords.h src/CColor.h src/CPaddle.h \
 src/CLife.h src/CBrick.h src/CBall.h
build/CScoreBoard.o: src/CScoreBoard.cpp src/CScoreBoard.h src/CLetter.h \
 src/CObject.h src/CCoords.h src/CColor.h
build/CSpeedModifier.o: src/CSpeedModifier.cpp src/CSpeedModifier.h \
 src/CBaseModifier.h src/CBall.h src/CPaddle.h src/CObject.h \
 src/CCoords.h src/CColor.h src/CLife.h src/CBrick.h
build/CSplitModifier.o: src/CSplitModifier.cpp src/CSplitModifier.h \
 src/CBaseModifier.h src/CBall.h src/CPaddle.h src/CObject.h \
 src/CCoords.h src/CColor.h src/CLife.h src/CBrick.h
build/CWidthModifier.o: src/CWidthModifier.cpp src/CWidthModifier.h \
 src/CBaseModifier.h src/CBall.h src/CPaddle.h src/CObject.h \
 src/CCoords.h src/CColor.h src/CLife.h src/CBrick.h
build/main.o: src/main.cpp src/CApplication.h src/CRenderer.h src/CScoreBoard.h \
 src/CLetter.h src/CObject.h src/CCoords.h src/CColor.h src/CPaddle.h \
 src/CLife.h src/CBrick.h src/CBall.h src/CGame.h src/EGameState.h \
 src/CInputManager.h src/CLevel.h src/CWidthModifier.h \
 src/CBaseModifier.h src/CLifeModifier.h src/CSpeedModifier.h \
 src/CBreakModifier.h src/CSplitModifier.h



