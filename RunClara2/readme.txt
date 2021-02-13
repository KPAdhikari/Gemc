
https://claraweb.jlab.org/clara/docs/clas/hands-on.html
=================
I did the following:
-
* mkdir RunClara2
* cd RunClara2
* mkdir ClaraUserData     
-        * (can be any name but we have to assign it to $CLARA_USER_DATA env. var.)
* source setClaraEnv.csh
-        * Here I have already created setClaraEnv.csh that defines two env. vars.
-        -   setenv CLARA_HOME /work/clas12/rg-f/software/myClara
-        -   setenv CLARA_USER_DATA /..../RunClara2/ClaraUserData


=================

we have to perform the following steps:

    Set environmental variable CLARA_HOME pointing to the common installation directory. Make sure you have read and execute permissions in that file system.

    Set environmental variable CLARA_USER_DATA that points to a directory where you will store Clara application service composition and data-set description files, as well as data processing logs, and possibly actual data files.

    Run the Clara CLI.

It is recommended for the $CLARA_USER_DATA directory to have a specific file structure:

������ config
������ data
��   ������ input
��   ������ output
������ log

It is OK not to create the structure by hand. Clara CLI (command line interface) will check/create the necessary file structure at the startup.

Let us start Clara CLI by typing the following:

========================
 $CLARA_HOME/bin/clara-shell

            
         4.3
          

 Run 'help' to show available commands.

clara>
=======================
It��s a success��

Now we can play by typing help and learn more about this interactive shell that makes data processing (including application customization, data-set selection, application deployment, scaling, and monitoring, and much more) simply an enjoyable experience.

Since we are not getting any younger, let us spare some time and show how we can reconstruct a given data file locally, i.e. on a local (on your own) computer.

#################### Processing a data file ###########################

Clara considers default locations to access data files, the application service-composition file (usually services.yaml, yet it can have any arbitrary name), data-set description file (e.g. files.txt, a text file containing the names of all data files) as well as log files (usually for every data processing Clara creates two log files: DPE and workflow-manager logs). To see the default locations/settings, type in the CLI the following command:

clara> show config

servicesFile:        "$CLARA_HOME/config/services.yaml"
fileList:            "$CLARA_USER_DATA/config/files.txt"
inputDir:            "$CLARA_USER_DATA/data/input"
outputDir:           "$CLARA_USER_DATA/data/output"
outputFilePrefix:    "out_"
logDir:              "$CLARA_USER_DATA/log"
session:             "gurjyan"
description:         "clara"
farm.cpu:            0
farm.memory:         0
farm.disk:           5
farm.time:           1440
farm.os:             "centos7"
farm.node:           ""
farm.exclusive:      ""
farm.stage:          NO VALUE
farm.track:          "debug"
farm.scaling:        0
farm.system:         "jlab"

Usually show config will show full path with environmental variables resolved.

Usually show config will show full path with environmental variables resolved.

Note that these are the default settings, and user can change them to point to different locations, with the exception of the logDir during the farm deployment.
During the farm deployment the logDir will be defined buy the $CLARA_USER_DATA environmental variable. In case $CLARA_USER_DATA/log is not defined or accessible Clara will default to the $CLARA_HOME/log.

Now let us switch to other workspace, or just simple exit the Clara CLI (Ctrl-C). First thing we have to do is to copy (or jget) our data file into the $CLARA_USER_DATA/data/input directory. E.g.

$ cp /work/clas12/data/clas_004013.0.hipo $CLARA_USER_DATA/data/input/

Next we create the files.txt file in the $CLARA_USER_DATA/config dir and add a single line to it:

$ cat $CLARA_USER_DATA/config/files.txt
clas_004013.0.hipo

For this exercise we will be using the official (commonly distributed) CLAS12 reconstruction application service composition file ($CLARA_HOME/config/services.yaml). That��s it. Let us call again the Clara CLI and start the processing by typing run local:

$ $CLARA_HOME/bin/clara-shell

            
         4.3
            
            
        
         


 Run 'help' to show available commands.

clara> run local
Distribution  :    clara-cre-4.3.5
CLAS12 plugin :    coatjava-5c.7.5

==========================================
               CLARA FE/DPE
==========================================
 Name             = 129.57.70.24%7220_java
 Session          = gurjyan_clara
 Start time       = 2019-01-31 16:35:22
 Version          = 4.3
 Lang             = Java
 Pool size        = 10

 Proxy Host       = 129.57.70.24
 Proxy Port       = 7220
==========================================
==========================================
            CLARA Orchestrator
==========================================
 Front-end          = 129.57.70.24%7220_java
 Start time         = 2019-01-31 16:35:23
 Threads            = 20

 Input directory    = /u/group/da/vhg/testbed/clara/work/data/input
 Output directory   = /u/group/da/vhg/testbed/clara/work/data/output
 Output file prefix = out_
 Number of files  = 4
==========================================
2019-01-31 16:35:23.692: Waiting for local node...
2019-01-31 16:35:23.841: Start processing on 129.57.70.24...
2019-01-31 16:35:23.841: Searching services in 129.57.70.24...
2019-01-31 16:35:23.851: Deploying services in 129.57.70.24...
2019-01-31 16:35:24: started container = 129.57.70.24%7220_java:gurjyan
[HipoDataSync] ---> dictionary size = 120
[HipoDataSync] ---> dictionary size = 120
2019-01-31 16:35:24: started service = 129.57.70.24%7220_java:gurjyan:DataManager  pool_size = 1
 SVT geometry constants loaded ? true
2019-01-31 16:35:24: started service = 129.57.70.24%7220_java:gurjyan:HipoToHipoReader  pool_size = 1
2019-01-31 16:35:24: started service = 129.57.70.24%7220_java:gurjyan:HipoToHipoWriter  pool_size = 1
2019-01-31 16:35:25: started service = 129.57.70.24%7220_java:gurjyan:FTHODO  pool_size = 20
2019-01-31 16:35:25: started service = 129.57.70.24%7220_java:gurjyan:MAGFIELDS  pool_size = 20
2019-01-31 16:35:25: started service = 129.57.70.24%7220_java:gurjyan:FTOFHB  pool_size = 20
2019-01-31 16:35:25: started service = 129.57.70.24%7220_java:gurjyan:FTEB  pool_size = 20
2019-01-31 16:35:25: started service = 129.57.70.24%7220_java:gurjyan:DCHB  pool_size = 20
2019-01-31 16:35:25: started service = 129.57.70.24%7220_java:gurjyan:FTCAL  pool_size = 20
2019-01-31 16:35:25: started service = 129.57.70.24%7220_java:gurjyan:CTOF  pool_size = 20
...
...

If you get this console printouts then congratulations!!! You can go and have a drink now. No seriously. This will take a while. Go��

Are you back? While you were drinking, and having fun I was working. That��s fine�� I like working, because it mesmerizes me. I can sit and look at it for hours :)

The processing is complete. If everything went smooth we will get a benchmark results on the CLI console, indicating total and average processing times in each service engine of the reconstruction application, average time spent by the entire application and time spent by workflow management system (orchestrator).

2019-02-01 09:19:09.169: Benchmark results:
2019-02-01 09:19:09.170:   READER           2000 events   total time =     0.21 s    average event time =    0.10 ms
2019-02-01 09:19:09.171:   MAGFIELDS        2000 events   total time =     0.02 s    average event time =    0.01 ms
2019-02-01 09:19:09.171:   FTCAL            2000 events   total time =     0.35 s    average event time =    0.18 ms
2019-02-01 09:19:09.172:   FTHODO           2000 events   total time =     0.55 s    average event time =    0.27 ms
2019-02-01 09:19:09.173:   FTEB             2000 events   total time =     0.18 s    average event time =    0.09 ms
2019-02-01 09:19:09.173:   DCHB             2000 events   total time =  1088.39 s    average event time =  544.20 ms
2019-02-01 09:19:09.174:   FTOFHB           2000 events   total time =     3.19 s    average event time =    1.60 ms
2019-02-01 09:19:09.175:   EC               2000 events   total time =     2.57 s    average event time =    1.29 ms
2019-02-01 09:19:09.176:   CVT              2000 events   total time =    93.01 s    average event time =   46.51 ms
2019-02-01 09:19:09.176:   CTOF             2000 events   total time =     4.03 s    average event time =    2.02 ms
2019-02-01 09:19:09.177:   CND              2000 events   total time =    17.64 s    average event time =    8.82 ms
2019-02-01 09:19:09.177:   HTCC             2000 events   total time =     0.46 s    average event time =    0.23 ms
2019-02-01 09:19:09.178:   LTCC             2000 events   total time =     0.43 s    average event time =    0.21 ms
2019-02-01 09:19:09.178:   RICH             2000 events   total time =     0.92 s    average event time =    0.46 ms
2019-02-01 09:19:09.179:   EBHB             2000 events   total time =     4.43 s    average event time =    2.22 ms
2019-02-01 09:19:09.179:   DCTB             2000 events   total time =   281.84 s    average event time =  140.92 ms
2019-02-01 09:19:09.180:   FTOFTB           2000 events   total time =     3.93 s    average event time =    1.97 ms
2019-02-01 09:19:09.180:   EBTB             2000 events   total time =     6.48 s    average event time =    3.24 ms
2019-02-01 09:19:09.181:   WRITER           2000 events   total time =     6.76 s    average event time =    3.38 ms
2019-02-01 09:19:09.181:   TOTAL            2000 events   total time =  1515.40 s    average event time =  757.70 ms
2019-02-01 09:19:09.182: Average processing time  =   41.02 ms
2019-02-01 09:19:09.182: Total processing time    =   82.04 s
2019-02-01 09:19:09.182: Total orchestrator time  =   89.80 s
2019-02-01 09:19:09.183: Processing is complete.

Where is my output

Reconstructed file will be physically stored in the outputDir: $CLARA_USER_DATA/data/output. (Remember the CLI show config command?).

clara> show outputDir
total 81M
-rw-r--r-- 1 gurjyan da 21M Feb  1 09:18 out_clas_004013.0.hipo

The data processing log files will be stored in the logDir: $CLARA_USER_DATA/log.

clara> show logDir
total 325M
-rwxr-xr-x 1 gurjyan da 4.0K Jan 30 15:06 129.57.75.136_gurjyan_clara_orch.log
-rwxr-xr-x 1 gurjyan da  89K Jan 30 15:12 129.57.75.136_gurjyan_clara_fe_dpe.log

Now a little bit about the file naming convention. As you can see the reconstructed file name is created by adding the out_ prefix to the actual input data file name. This prefix is configurable, and can be set/changed using the following CLI command:

clara> set outputFilePrefix myOwnPrefix_
clara> show config

Clara log files are critical for data preservation, monitoring and debugging. So, that is the reason log file names some of the important information, such as the node where the processing was performed (in our example node IP 129.57.75.136), data processing session(by default data processing session is set to be the user name. In our example session=gurjyan), and data processing description ( for this example description=clara). The data processing session and description are CLI configurable options and can be set by the following command set:

clara> set session myOwnSession
clara> set description myOwnDescription
clara> show config

We recommend the session and the description to be unique for every new data-set processing.

We can do a lot without exiting the Clara CLI. For e.g. we can analyse the log files using the following commands:

clara> show logDPE
clara> show logOrchestrator

Application customization

While CLAS12 reconstruction application is the best-in-class :), it won��t do you any good if it is missing one key feature. Clara provides application flexible customization to fit your needs. E.g. you want to pass engine specific configuration options or change application service composition by adding or removing service engines, etc. All this is possible with Clara. You will understand me if you ever played with LEGO. Ok let us see it on an example. Below is the official CLAS12 reconstruction application service-composition, that can be accessed through the following command:

clara> show services
io-services:
  reader:
    class: org.jlab.clas.std.services.convertors.HipoToHipoReader
    name: HipoToHipoReader
  writer:
    class: org.jlab.clas.std.services.convertors.HipoToHipoWriter
    name: HipoToHipoWriter
services:
  - class: org.jlab.clas.swimtools.MagFieldsEngine
    name: MAGFIELDS
  - class: org.jlab.rec.ft.cal.FTCALEngine
    name: FTCAL
  - class: org.jlab.rec.ft.hodo.FTHODOEngine
    name: FTHODO
  - class: org.jlab.rec.ft.FTEBEngine
    name: FTEB
  - class: org.jlab.service.dc.DCHBEngine
    name: DCHB
  - class: org.jlab.service.ftof.FTOFHBEngine
    name: FTOFHB
  - class: org.jlab.service.ec.ECEngine
    name: EC
  - class: org.jlab.rec.cvt.services.CVTReconstruction
    name: CVT
  - class: org.jlab.service.ctof.CTOFEngine
    name: CTOF
#  - class: org.jlab.service.cnd.CNDEngine
  - class: org.jlab.service.cnd.CNDCalibrationEngine
    name: CND
  - class: org.jlab.service.htcc.HTCCReconstructionService
    name: HTCC
  - class: org.jlab.service.ltcc.LTCCEngine
    name: LTCC
  - class: org.jlab.rec.rich.RICHEBEngine
    name: RICH
  - class: org.jlab.service.eb.EBHBEngine
    name: EBHB
  - class: org.jlab.service.dc.DCTBEngine
    name: DCTB
  - class: org.jlab.service.ftof.FTOFTBEngine
    name: FTOFTB
  - class: org.jlab.service.eb.EBTBEngine
    name: EBTB
configuration:
  io-services:
    writer:
      compression: 2
# settings below are for GEMC, compatible with 4a.2.4
  services:
    MAGFIELDS:
      solenoidMap: Symm_solenoid_r601_phi1_z1201_13June2018.dat
      torusMap: Symm_torus_r2501_phi16_z251_24Apr2018.dat
      solenoidShift: "0.0"
      torusXShift: "0.0"
      torusYShift: "0.0"
      torusZShift: "0.0"
    DCHB:
      useStartTime: "true"
      wireDistortionsFlag: "false"
      geomDBVariation: may_2018_engineers
    DCTB:
      geomDBVariation: may_2018_engineers

mime-types:
  - binary/data-hipo

The command above printed the content of the Clara application composition YAML file, the location of which is configurable through the following command:

clara> set servicesFile /myOwnDir/myOwnService.yaml
clara> show config

Noticed that I am calling show config after every set command just to remind you about this useful command that shows data processing application configuration options. It does not have any other purpose other than that (arguably useful, ha ha).

Ok, let us examine CLAS12 reconstruction official services.yaml file, the default location being at:

clara> show config
...
servicesFile:        "$CLARA_HOME/config/services.yaml"
...

The service composition file consists of the following sections:

    Stream builder and stream consumer services. This are IO services that access a data source and create a stream of data quanta that are dispatched to data processing services.

    io-services:
      reader:
        class: org.jlab.clas.std.services.convertors.HipoToHipoReader
        name: HipoToHipoReader
      writer:
        class: org.jlab.clas.std.services.convertors.HipoToHipoWriter
        name: HipoToHipoWriter

    Data processing services.

    services:
      - class: org.jlab.clas.swimtools.MagFieldsEngine
        name: MAGFIELDS
      - class: org.jlab.rec.ft.cal.FTCALEngine
        name: FTCAL

    We describe a service by defining the service engine clas and a by giving a name. So, this means that we can have multiple services with different names sharing the same engine. May be not so useful, but one can configure the same engine differently and build and stream events through a limited cycle loop (note: no programing is necessary).

    Section describing configuration options for services. In this section users can describe configuration parameters for IO and general for all processing services, as well as configuration options for a specific service (e.g. parameter useStartTime for DCHB service).

    configuration:
     global:
       magnet:
         torus: -1
         solenoid: -1
       ccdb:
         run: 101
         variation: custom
       runtype: mc
       runmode: calibration
       io-services:
          writer:
            compression: 2
      services:
        DCHB:
          useStartTime: "true"
          wireDistortionsFlag: "false"
          geomDBVariation: may_2018_engineers
        DCTB:
          geomDBVariation: may_2018_engineers

    Data tyoe of the streaming event (data quantum).

    mime-types:
      - binary/data-hipo

So you can add a new service to the application by providing class of the an engine and an arbitrary name (preferably something descriptive). Removing a service is as simple as deleting or commenting out the two lines in yml file, describing a service.

E.g. below shows the CLAS12 modified reconstruction application ,where we keep two standard services from the reconstruction official application and add two services, sharing the same engine. Here we demonstrate testing and debugging a new reconstruction engine with two different configuration options.

clara> set servicesFile /myOwnDir/myOwnService.yaml
clara> show services

io-services:
  reader:
    class: org.jlab.clas.std.services.convertors.HipoToHipoReader
    name: HipoToHipoReader
  writer:
    class: org.jlab.clas.std.services.convertors.HipoToHipoWriter
    name: HipoToHipoWriter
services:
  - class: org.jlab.clas.swimtools.MagFieldsEngine
    name: MAGFIELDS
#  - class: org.jlab.rec.ft.cal.FTCALEngine
#    name: FTCAL
  - class: org.jlab.rec.ft.FTEBEngine
    name: FTEB
  - class: org.jlab.service.dc.DCHBEngine
    name: DCHB
  - class: my.own.service.dc.DCHBEngineVersion
    name: myDCHB1
  - class: my.own.service.dc.DCHBEngineVersion
    name: myDCHB2
configuration:
  io-services:
    writer:
      compression: 2
# settings below are for GEMC, compatible with 4a.2.4
  services:
    DCHB1:
      useStartTime: "true"
      wireDistortionsFlag: "false"
      geomDBVariation: may_2018_engineers
    DCHB2:
      useStartTime: "flase"
      wireDistortionsFlag: "true"
      geomDBVariation: feb_2019_engineers
mime-types:
  - binary/data-hipo

Clara application composition YAML file is a representation of a directed graph, where data flows from services described at the top to the bottom.
Running on a farm

Old McDonald sends a farm job e-i-e-i-o��

Yup, this is that easy. You do not have to write a farm submission scripts, and farm deployment can be done without leaving the Clara CLI. Let us show it on an example.

Before we continue remember that a farm submission must have a unique session. This is critical in case farm control system lands your jobs on the same node.

I have a data set consisting of 4 files (I can see my data-set using the command: show files. see below), and I want to process it on the JLAB farm.

clara> show files
clas_004013.0.hipo
clas_004013.1.hipo
clas_004013.2.hipo
clas_004013.3.hipo

The following settings will configure my farm deployment:

    Make sure user data is accessible from the farm mounted file system. This includes input/output data directories, application and data-set description files, log directory and farm-job PBS/SLURM scripts.

    clara> set inputDir /work/clas12/gurjyan/Testbed/clara/data/input
    clara> set outputDir /work/clas12/gurjyan/Testbed/clara/data/out
    clara> set servicesFile /work/clas12/gurjyan/Testbed/clara/services.yaml
    clara> set fileList /work/clas12/gurjyan/Testbed/clara/files.txt
    clara> set logDir /work/clas12/gurjyan/Testbed/clara/log

    You can minimize manual settings in CLI (using default settings) by defining CLARA_USER_DATA environmental variable pointing to a user-data directory that is visible to the farm system. Note that this must be done prior running the clara-shell executable.

    Define the data-processing session and the description.

    clara> set session gurjyanSession
    clara> set description gurjyanDescription

    Set the vertical scaling parameter (so called multi-threading, i.e. how many threads you wish will process the data in parallel).

    clara> set farm.cpu 8

    Request the memory and the disk space for the job.

    clara> set farm.memory 30
    clara> set farm.disk 10

These are typical settings for 8 core jobs that will work on all JLAB farm nodes.

That��s it. Now we launch the farm job, yet, it is a good practise check the settings before a farm deployment (I am sure you remember the CLI command show config).

To run a farm job execute the following command in the CLI:

clara> run farm

Parsing script ... (it may take while)
<jsub><request><index>30283608</index><jobIndex>63238147</jobIndex></request></jsub>

Now we can monitor the job submission by:

clara> show farmStatus

JOB_ID    USER      STAT    QUEUE      EXEC_HOST   JOB_NAME         SUBMIT_TIME   CPU_TIME  WALLTIME  ACCOUNT
63238147  gurjyan     A    priority    --         ...urjyan-clara   Feb 05 13:55  --         --         clas12

You can examine actual farm submission and shell executable scripts created by Clara in the $CLARA_USER_DATA/config directory (.jsub and .sh files).

$ cd $CLARA_USER_DATA/config
$ ls
farm_gurjyan_clara.jsub	  farm_gurjyan_clara.sh  files.txt  service.yaml

There are more farm-job control parameters that help users to further customize the farm deployments. E.g. user can process a given data set in multiple farm nodes in parallel (find more details in here).

clara> set farm.scaling 4

This command will divide entire data-set into groups of 4 files and will process each group in a different farm node. This is known as the Clara horizontal scaling.
Farm node flavors

Also user can request data processing on specific node flavor of the farm.

The JLAB scientific computing farm consists of the following hardware systems:

    farm18, 6148 CPU @ 2.4 Gz, cores = 80
    farm16, E5-2697 v4 @ 2.3 Gz, cores = 72
    farm14, E5-2670 v3 @ 2.3 Gz, cores = 48
    farm13, E5-2650 v2 @ 2.6 Gz, cores = 32
    qcd12s, E5-2650 0 @ 2.0 Gz, cores = 32

To run data processing on a specific farm hardware you need to set the farm.node parameter. E.g. the command below will request data processing only on farm.18 nodes.

clara> set farm.node farm18

Examples above will use farm in so called sharing mode, where in a single farm node there might be multiple jobs running owned by multiple users. In this mode data processing performance can not be properly optimized due to the unpredicted resource allocation requests. However, Clara can request an exclusive node for a data processing, where only your job will be running. In this case Clara will perform hardware level optimizations to achieve maximum performance.

E.g. the command below requests an exclusive access to a farm18 node:

clara> set farm.exclusive farm18

The exclusive mode works for only SLURM controlled farm nodes. For the exclusive mode on the SLURM farm, you do not have to define farm.memory and farm.cpu parameters, since Clara will set these values for you to guarantee maximum performance.

How I can get then farm node exclusively in PBS you might ask? Even though farm.exclusive parameter is inactive for PBS jobs, you can request an exclusive node on PBS by setting proper memory and core requests. E.g request the farm18 exclusive node on PBS:

clara> set farm.node farm18
clara> set farm.cpu 80
clara> set farm.memory 00
clara> set farm.disk 25

or request the farm16 exclusive node on PBS:

clara> set farm.node farm16
clara> set farm.cpu 72
clara> set farm.memory 60
clara> set farm.disk 25

Farm staging

One other important parameter to be considered is the farm.stage. This will tell Clara workflow management system to stage files one-by-one in the local file system of the farm computing node. This operation is critical for IO optimizations, since local IO is considerably faster that shared file system IO. E.g.

clara> set farm.stage /scratch/clara/gurjyan

The /scratch/clara is the created directory on all JLAB farm nodes (much like /scratch/pbs). For the proper staging and file transfers user must request a subdirectory specific for his/her processing (in the example the subdir is gurjyan).

In case you are running on JLAB farm, the easies and safest would be to request default staging directory: /scratch/clara/$USER.

clara> set farm.stage default

To get more information on farm deployment parameters here.
Choosing between PBS and SLURM

All your actions and created Clara CLI command sets will not change to launch data processing jobs on a farm controlled by PBS or SLURM batch control systems. Clara is transparent in this sense. If you want your jobs to end up on SLURM or PBS controlled farms the only thing you need to do is to change the PATH variable in your startup script. E.g. changing PATH variable in the .cshrc file:

$ set path = ( /site/scicomp/auger-slurm/bin $path )

That��s it. now you are ready to process data on SLURM controlled farm.

The default farm job .out and .err files are no longer copied to the home directory of a user (as in case of the PBS), instead it will be directly written to the central location under /lustre/expphy/farm_out/, name pattern will be JOB_NAME-AUGER_JOB_ID-HOSTNAME.out and JOB_NAME-AUGER_JOB_ID-HOSTNAME.err.

There are useful commands in SLURM, that are not ported into Clara CLI (there is no intention to make Clara Jack of all trades), such as slurmHosts, slurmJobs, slurmQueues, etc, that help to see available nodes, running jobs and their statuses. Please refer to the scicomp web site for more information.
Creating scripts

This entire time we were typing CLI command in the Clara shell. What if I exit the shell? Do I need to type all this commands that I discovered and tested when I start a new Clara shell?

If this is the case you might suggest watering me twice a day.

But wait�� do not try to get easy exercise by jumping into conclusions.

Before exiting the CLI I recommend you save whatever you typed in the shell as a clara script by:

clara> save myTest.clara

The next time you start a shell you can type something like:

$ $CLARA_HOME/bin/clara-shell myTest.clara

You can get more on Clara scripting in here
