
Ref: https://userweb.jlab.org/~nathand/rgf/sim/gemc.html

##  GEMC Simulation Instructions
The documentation and release information for GEMC can be found at this website: gemc.jlab.org/gemc/html/index.html

The most current development version of RTPC in GEMC is located at /group/bonus/gemc/devel/, which as of 12 July 2020 differs from the official GEMC release in the expressions/parameters for drift electron behavior. In this directory you can find the gcard to run gemc with the RGF configuration (rgf_spring2020_lund.gcard). This gcard runs with an input from an external event generator (lund/ep_34118_20.lund), which was updated May 2020. This lund file has one primary ep event and 20 additional protons to act as "background." The RTPC hit process class in the GEMC source code takes those background protons and shifts the ionization electron times randomly between -8 and 8 µsec.

There are a few files in the GEMC source directory that are important specifically for RTPC. That is: source/hitprocess/clas12/rtpc_hitprocess.h and source/hitprocess/clas12/rtpc_hitprocess.cc, where the Garfield++ generated parameters have been implemented. Whenever you change something in the source directory, you have to recompile with scons. In /group/bonus/gemc/devel/source/, run
> scons OPT=1 -j4

To update the Official GEMC source code, you need to pull the latest version from the GitHub repo at github.com/gemc/source, update the relevant code and create a pull request.

If you want to change the RTPC geometry, the files are located in /group/bonus/gemc/devel/detectors/clas12/rtpc/, which contains the Perl files for the geometry, materials, hits, and banks. If you modify any of these, you have to reconfigure the group with
> ./rtpc.pl config.dat

To update the Official GEMC detector code, you need to pull the latest version from the GitHub repo at github.com/gemc/detectors, update the relevant code and create a pull request.

For complete instructions on creating a proper pull request from the Official GEMC GitHub repo, visit gemc.jlab.org/gemc/html/contributing.html