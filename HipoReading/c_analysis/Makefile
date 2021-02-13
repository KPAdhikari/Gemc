#********************************************************
# MAKEFILE for BUILDING EXAMPLES FOR HIPO4 LIBRARY
# AUTHOR: GAVALIAN DATE: 10/24/2018
#********************************************************
HIPOCFLAGS  := -I/w/hallb-scifs17exp/clas/claseg4/adhikari/Bonus12/Gemc/MHcpdStuff/hipo/hipo4
HIPOLIBS    := -L/w/hallb-scifs17exp/clas/claseg4/adhikari/Bonus12/Gemc/MHcpdStuff/hipo/lib -lhipo4

LZ4LIBS     := -L/work/clas12/mhattawy/hipo/lz4/lib -llz4
LZ4INCLUDES := -I/work/clas12/mhattawy/hipo/lz4/lib


ROOTLIBS     := -L$(ROOTSYS)/lib -lCore -lCling -lRIO -lHist -lTree -lGpad -lGraf -lRint -lGraf3d -lPhysics -lMathCore -lMatrix -lTreePlayer -lGX11TTF -lGX11 -lGui -lGed -lGeom -lFitPanel
ROOTINCLUDES := -I$(ROOTSYS)/include


CXX       := g++
CXXFLAGS  += -Wall -fPIC -std=c++11 `root-config --libs` `root-config --glibs`
LD        := g++
LDFLAGS   :=


all:  kp_hipo

kp_hipo: kp_hipo.o
	$(CXX) -o kp_hipo $<   $(HIPOLIBS) $(LZ4LIBS) $(ROOTLIBS)
kp_hipoPrintBanks: kp_hipoPrintBanks.o
	$(CXX) -o kp_hipoPrintBanks $<   $(HIPOLIBS) $(LZ4LIBS) $(ROOTLIBS)

rgb_10GeV_D2: rgb_10GeV_D2.o
	$(CXX) -o rgb_10GeV_D2 $<   $(HIPOLIBS) $(LZ4LIBS) $(ROOTLIBS)

testingdictionary: testingdictionary.o
	$(CXX) -o testingdictionary $<   $(HIPOLIBS) $(LZ4LIBS) $(ROOTLIBS)

plotLundEvents: plotLundEvents.o
	$(CXX) -o plotLundEvents $< $(HIPOLIBS) $(LZ4LIBS) $(ROOTLIBS)

clean:
	@echo 'Removing all build files'
	@rm -rf *.o rgb_elastic_H

%.o: %.cc
	$(CXX) -c $< -O2 $(CXXFLAGS) $(HIPOCFLAGS) $(LZ4INCLUDES) $(ROOTINCLUDES)
