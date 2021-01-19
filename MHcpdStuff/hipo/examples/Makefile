#********************************************************
# MAKEFILE for BUILDING EXAMPLES FOR HIPO4 LIBRARY
# AUTHOR: GAVALIAN DATE: 10/24/2018
#********************************************************
HIPOCFLAGS  := -I../hipo4
HIPOLIBS    := -L../lib -lhipo4

LZ4LIBS     := -L../lz4/lib -llz4
LZ4INCLUDES := -I../lz4/lib


ROOTLIBS     := -L$(ROOTSYS)/lib -lCore -lCling -lRIO -lHist -lTree -lGpad -lGraf -lRint -lGraf3d -lPhysics -lMathCore -lMatrix -lTreePlayer -lGX11TTF -lGX11 -lGui -lGed -lGeom -lFitPanel
ROOTINCLUDES := -I$(ROOTSYS)/include


CXX       := g++
CXXFLAGS  += -Wall -fPIC -std=c++11 `root-config --libs` `root-config --glibs`
LD        := g++
LDFLAGS   :=


all:  readFile

readEvents: readEvents.o
	$(CXX) -o readEvents $<  $(HIPOLIBS) $(LZ4LIBS) $(ROOTLIBS)

writeEvents: writeEvents.o
	$(CXX) -o writeEvents $<   $(HIPOLIBS) $(LZ4LIBS)

readFile: readFile.o
	$(CXX) -o readFile $<   $(HIPOLIBS) $(LZ4LIBS) $(ROOTLIBS)

writeFile: writeFile.o
	$(CXX) -o writeFile $<   $(HIPOLIBS) $(LZ4LIBS)

schema: schema.o
	$(CXX) -o schema $<   $(HIPOLIBS) $(LZ4LIBS)

builder: builder.o
	$(CXX) -o builder $<   $(HIPOLIBS) $(LZ4LIBS)


clean:
	@echo 'Removing all build files'
	@rm -rf *.o readEvents schema *~ builder writeEvents writeFile readFile

%.o: %.cc
	$(CXX) -c $< -O2 $(CXXFLAGS) $(HIPOCFLAGS) $(LZ4INCLUDES) $(ROOTINCLUDES)
