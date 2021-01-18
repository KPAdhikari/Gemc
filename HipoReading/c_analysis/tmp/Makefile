#********************************************************
# MAKEFILE for BUILDING EXAMPLES FOR HIPO4 LIBRARY
# AUTHOR: GAVALIAN DATE: 10/24/2018
#********************************************************
HIPOCFLAGS  := -I/work/clas12/mhattawy/hipo/hipo4
HIPOLIBS    := -L/work/clas12/mhattawy/hipo/lib -lhipo4

LZ4LIBS     := -L/work/clas12/mhattawy/hipo/lz4/lib -llz4
LZ4INCLUDES := -I/work/clas12/mhattawy/hipo/lz4/lib


ROOTLIBS     := -L$(ROOTSYS)/lib -lCore -lCling -lRIO -lHist -lTree -lGpad -lGraf -lRint -lGraf3d -lPhysics -lMathCore -lMatrix -lTreePlayer -lGX11TTF -lGX11 -lGui -lGed -lGeom -lFitPanel
ROOTINCLUDES := -I$(ROOTSYS)/include


CXX       := g++
CXXFLAGS  += -Wall -fPIC -std=c++11 `root-config --libs` `root-config --glibs`
LD        := g++
LDFLAGS   :=


all:  rgb_10GeV_D2

rgb_10GeV_D2: rgb_10GeV_D2.o
	$(CXX) -o rgb_10GeV_D2 $<   $(HIPOLIBS) $(LZ4LIBS) $(ROOTLIBS)


clean:
	@echo 'Removing all build files'
	@rm -rf *.o rgb_elastic_H

%.o: %.cc
	$(CXX) -c $< -O2 $(CXXFLAGS) $(HIPOCFLAGS) $(LZ4INCLUDES) $(ROOTINCLUDES)
