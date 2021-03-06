Bank details from David Payette's testing... script:
ifarm1802.jlab.org> ./testingdictionary.exe ../../../../../HipoReading/c_analysis/out_ep_34118_20_15kEvs.hipo 
************************************************
*         >=<      :  ---------------------    *
*    ,.--'  ''-.   :  HIPO 4.0 I/O Library     *
*    (  )  ',_.'   :  Jefferson National Lab   *
*     Xx'xX        :  Date: 01/24/2019         *
************************************************

----------------------------------------
**** reader:: header version   : 6 
**** reader:: header length    : 56 
**** reader:: first record pos : 156604
**** reader:: trailer position : 522025176
**** reader:: file size        : 522026892
----------------------------------------
---> resizing internal compressed buffer size to from 0 to 6780
 resizing internal buffer from 0 to 4440
*** reader:: trailer record event count : 1

*****>>>>> compiled with c++11 support.
 EVENT  SIZE = 4440
                 32111    1           11         4416
structure : [32111,    1] type =   11, length =   4416
 number of rows = 138
**** reader::  # of events     : 15001 
---> resizing internal compressed buffer size to from 0 to 161612
 resizing internal buffer from 0 to 155952
compression type = 0 data length = 156492
 reading record at position       56, number of entries =   135

*****>>>>> compiled with c++11 support.
schema : {RAW::adc/20000/11}{crate/B,slot/B,channel/S,order/B,ADC/I,time/F,ped/S}
schema : {BMTRec::Hits/20100/21}{ID/S,sector/B,layer/B,strip/I,fitResidual/F,trkingStat/I,clusterID/S,trkID/S}
schema : {nn::tracks/4200/1}{id/B,x/F,y/F,tx/F,ty/F,qp/F}
schema : {BAND::adc/22100/11}{sector/B,layer/B,component/S,order/B,ADC/I,amplitude/I,time/F,ped/S}
schema : {RUN::config/10000/11}{run/I,event/I,unixtime/I,trigger/L,timestamp/L,type/B,mode/B,torus/F,solenoid/F}
schema : {RICH::clusters/21800/22}{id/S,size/S,sector/S,tile/S,pmt/S,charge/F,time/F,rawtime/F,x/F,y/F,z/F,wtime/F,wx/F,wy/F,wz/F}
schema : {RECHB::Scintillator/300/15}{index/S,pindex/S,detector/B,sector/B,layer/B,component/S,energy/F,time/F,path/F,chi2/F,x/F,y/F,z/F,hx/F,hy/F,hz/F,status/S,dedx/F}
schema : {RTPC::tracks/1720/2}{trkID/I,px/F,py/F,pz/F,vz/F,theta/F,phi/F,nhits/I,path/F,dedx/F}
schema : {BSTRec::LayerEffs/20200/26}{sector/B,layer/B,residual/F,status/B}
schema : {RTPC::pos/21900/14}{step/I,time/F,energy/F,posx/F,posy/F,posz/F,phi/F,tid/I}
schema : {TimeBasedTrkg::TBCrosses/20600/35}{id/S,status/S,sector/B,region/B,x/F,y/F,z/F,err_x/F,err_y/F,err_z/F,ux/F,uy/F,uz/F,err_ux/F,err_uy/F,err_uz/F,Segment1_ID/S,Segment2_ID/S}
schema : {HitBasedTrkg::HBTracks/20600/26}{id/S,status/S,sector/B,c1_x/F,c1_y/F,c1_z/F,c1_ux/F,c1_uy/F,c1_uz/F,c3_x/F,c3_y/F,c3_z/F,c3_ux/F,c3_uy/F,c3_uz/F,t1_x/F,t1_y/F,t1_z/F,t1_px/F,t1_py/F,t1_pz/F,Vtx0_x/F,Vtx0_y/F,Vtx0_z/F,p0_x/F,p0_y/F,p0_z/F,x/F,y/F,z/F,tx/F,ty/F,Cross1_ID/S,Cross2_ID/S,Cross3_ID/S,q/B,pathlength/F,chi2/F,ndf/S}
schema : {CVTRec::Cosmics/20500/28}{ID/S,trkline_yx_slope/F,trkline_yx_interc/F,trkline_yz_slope/F,trkline_yz_interc/F,theta/F,phi/F,chi2/F,ndf/S,Cross1_ID/S,Cross2_ID/S,Cross3_ID/S,Cross4_ID/S,Cross5_ID/S,Cross6_ID/S,Cross7_ID/S,Cross8_ID/S,Cross9_ID/S,Cross10_ID/S,Cross11_ID/S,Cross12_ID/S,Cross13_ID/S,Cross14_ID/S,Cross15_ID/S,Cross16_ID/S,Cross17_ID/S,Cross18_ID/S}
schema : {RECHB::Cherenkov/300/13}{index/S,pindex/S,detector/B,sector/B,nphe/F,time/F,path/F,chi2/F,x/F,y/F,z/F,dtheta/F,dphi/F,status/S}
schema : {BSTRec::Clusters/20200/22}{ID/S,sector/B,layer/B,size/S,ETot/F,seedE/F,seedStrip/I,centroid/F,centroidResidual/F,seedResidual/F,Hit1_ID/S,Hit2_ID/S,Hit3_ID/S,Hit4_ID/S,Hit5_ID/S,trkID/S}
schema : {CVTRec::Trajectory/20500/29}{id/S,detector/B,sector/B,layer/B,x/F,y/F,z/F,phi/F,theta/F,langle/F,centroid/F,path/F}
schema : {RECHB::Calorimeter/300/12}{index/S,pindex/S,detector/B,sector/B,layer/B,energy/F,time/F,path/F,chi2/F,x/F,y/F,z/F,hx/F,hy/F,hz/F,lu/F,lv/F,lw/F,du/F,dv/F,dw/F,m2u/F,m2v/F,m2w/F,m3u/F,m3v/F,m3w/F,status/S}
schema : {TimeBasedTrkg::TBSegmentTrajectory/20600/34}{segmentID/S,sector/B,superlayer/B,layer/B,matchedHitID/S,trkDoca/F}
schema : {CTOF::tdc/20400/12}{sector/B,layer/B,component/S,order/B,TDC/I}
schema : {REC::Cherenkov/300/33}{index/S,pindex/S,detector/B,sector/B,nphe/F,time/F,path/F,chi2/F,x/F,y/F,z/F,dtheta/F,dphi/F,status/S}
schema : {RICH::hadCher/21800/35}{id/B,hindex/B,pindex/B,emilay/B,emico/B,enico/B,emqua/S,mchi2/F,ch_min/F,ch_max/F,dt_max/F,ch_dir/F,ch_lat/F,ch_spe/F,best_PID/B,RQ_prob/F,el_prob/F,pi_prob/F,k_prob/F,pr_prob/F}
schema : {BMTRec::LayerEffs/20100/26}{sector/B,layer/B,residual/F,status/B}
schema : {FTOF::adc/21200/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S}
schema : {MC::Lund/40/3}{index/B,lifetime/F,type/B,pid/I,parent/B,daughter/B,px/F,py/F,pz/F,energy/F,mass/F,vx/F,vy/F,vz/F}
schema : {DETECTOR::lcpb/31000/34}{sector/B,etot/F,ein/F,time/F,path/F,x/F,y/F,z/F}
schema : {CND::clusters/20300/22}{id/S,sector/B,layer/B,component/S,nhits/S,energy/F,x/F,y/F,z/F,time/F,status/S}
schema : {MC::Header/40/0}{run/I,event/I,type/B,helicity/F}
schema : {TimeBasedTrkg::TBCovMat/20600/37}{id/S,C11/F,C12/F,C13/F,C14/F,C15/F,C21/F,C22/F,C23/F,C24/F,C25/F,C31/F,C32/F,C33/F,C34/F,C35/F,C41/F,C42/F,C43/F,C44/F,C45/F,C51/F,C52/F,C53/F,C54/F,C55/F}
schema : {RICH::hits/21800/21}{id/S,sector/S,tile/S,pmt/S,anode/S,x/F,y/F,z/F,time/F,rawtime/F,cluster/S,xtalk/S,duration/S}
schema : {RECHB::Track/300/16}{index/S,pindex/S,detector/B,sector/B,status/S,q/B,chi2/F,NDF/S}
schema : {BST::adc/20200/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S,timestamp/L}
schema : {MC::True/40/4}{detector/B,pid/I,mpid/I,tid/I,mtid/I,otid/I,trackE/F,totEdep/F,avgX/F,avgY/F,avgZ/F,avgLx/F,avgLy/F,avgLz/F,px/F,py/F,pz/F,vx/F,vy/F,vz/F,mvx/F,mvy/F,mvz/F,avgT/F,nsteps/I,procID/I,hitn/I}
schema : {MC::Event/40/1}{npart/S,atarget/S,ztarget/S,ptarget/F,pbeam/F,btype/S,ebeam/F,targetid/S,processid/S,weight/F}
schema : {RICH::response/21800/31}{index/S,pindex/S,detector/B,sector/B,layer/B,energy/F,time/F,path/F,chi2/F,x/F,y/F,z/F,hx/F,hy/F,hz/F,status/S}
schema : {HitBasedTrkg::HBCrosses/20600/25}{id/S,status/S,sector/B,region/B,x/F,y/F,z/F,err_x/F,err_y/F,err_z/F,ux/F,uy/F,uz/F,err_ux/F,err_uy/F,err_uz/F,Segment1_ID/S,Segment2_ID/S}
schema : {nn::dchits/4200/2}{id/B,index/S}
schema : {FTOF::clusters/21200/32}{id/S,status/S,trackid/S,sector/B,layer/B,component/S,energy/F,time/F,energy_unc/F,time_unc/F,x/F,y/F,z/F,x_unc/F,y_unc/F,z_unc/F}
schema : {REC::TrackCross/300/37}{index/S,pindex/S,detector/B,sector/B,layer/B,c_x/F,c_y/F,c_z/F,c_ux/F,c_uy/F,c_uz/F,status/S}
schema : {REC::Scintillator/300/35}{index/S,pindex/S,detector/B,sector/B,layer/B,component/S,energy/F,time/F,path/F,chi2/F,x/F,y/F,z/F,hx/F,hy/F,hz/F,status/S,dedx/F}
schema : {TimeBasedTrkg::TBClusters/20600/32}{id/S,status/S,sector/B,superlayer/B,Hit1_ID/S,Hit2_ID/S,Hit3_ID/S,Hit4_ID/S,Hit5_ID/S,Hit6_ID/S,Hit7_ID/S,Hit8_ID/S,Hit9_ID/S,Hit10_ID/S,Hit11_ID/S,Hit12_ID/S,avgWire/F,fitChisqProb/F,fitSlope/F,fitSlopeErr/F,fitInterc/F,fitIntercErr/F,size/B}
schema : {ECAL::peaks/20700/22}{id/S,status/S,sector/B,layer/B,energy/F,time/F,xo/F,yo/F,zo/F,xe/F,ye/F,ze/F,width/F}
schema : {LTCC::clusters/21600/22}{id/S,status/B,sector/B,segment/S,x/F,y/F,z/F,nphe/F,time/F,nHits/S,minTheta/F,maxTheta/F,minPhi/F,maxPhi/F}
schema : {TAGGER::tgpb/31000/41}{status/B,tid/S,eid/S,time/F,energy/F}
schema : {DC::tdc/20600/12}{sector/B,layer/B,component/S,order/B,TDC/I}
schema : {RICH::hadrons/21800/32}{id/S,hit_index/S,particle_index/S,traced_the/F,traced_phi/F,traced_hitx/F,traced_hity/F,traced_hitz/F,traced_time/F,traced_path/F,traced_ilay/S,traced_ico/S,traced_emix/F,traced_emiy/F,traced_emiz/F,EtaC_ele/F,EtaC_pi/F,EtaC_k/F,EtaC_pr/F,EtaC_min/F,EtaC_max/F}
schema : {BSTRec::Crosses/20200/25}{ID/S,sector/B,region/B,x/F,y/F,z/F,err_x/F,err_y/F,err_z/F,ux/F,uy/F,uz/F,Cluster1_ID/S,Cluster2_ID/S,trkID/S}
schema : {FTHODO::adc/21100/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S}
schema : {HTCC::rec/21500/22}{id/S,nhits/S,nphe/F,ntheta/S,nphi/S,mintheta/S,maxtheta/S,minphi/S,maxphi/S,time/F,theta/F,dtheta/F,phi/F,dphi/F,x/F,y/F,z/F}
schema : {FTOF::matchedclusters/21200/33}{sector/B,paddle_id1A/S,paddle_id1B/S,clus_1Aid/S,clus_1Bid/S,clusSize_1A/S,clusSize_1B/S,tminAlgo_1B_tCorr/F,midbarAlgo_1B_tCorr/F,EmaxAlgo_1B_tCorr/F}
schema : {ECAL::adc/20700/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S}
schema : {FMT::adc/20800/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S,integral/I,timestamp/L}
schema : {BMT::adc/20100/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S,integral/I,timestamp/L}
schema : {ECAL::calib/20700/24}{sector/B,layer/B,energy/F,rawEU/F,rawEV/F,rawEW/F,recEU/F,recEV/F,recEW/F}
schema : {BMTRec::Crosses/20100/25}{ID/S,sector/B,region/B,x/F,y/F,z/F,err_x/F,err_y/F,err_z/F,ux/F,uy/F,uz/F,Cluster1_ID/S,Cluster2_ID/S,trkID/S}
schema : {BSTRec::Hits/20200/21}{ID/S,sector/B,layer/B,strip/I,fitResidual/F,trkingStat/I,clusterID/S,trkID/S}
schema : {RUN::rf/10000/12}{id/S,time/F}
schema : {HitBasedTrkg::HBSegmentTrajectory/20600/24}{segmentID/S,sector/B,superlayer/B,layer/B,matchedHitID/S,trkDoca/F}
schema : {LTCC::adc/21600/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S}
schema : {CND::tdc/20300/12}{sector/B,layer/B,component/S,order/B,TDC/I}
schema : {HTCC::adc/21500/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S}
schema : {RAW::vtp/20000/14}{crate/B,word/I}
schema : {CVTRec::Tracks/20500/26}{ID/S,fittingMethod/B,c_x/F,c_y/F,c_z/F,c_ux/F,c_uy/F,c_uz/F,pathlength/F,q/B,p/F,pt/F,phi0/F,tandip/F,z0/F,d0/F,cov_d02/F,cov_d0phi0/F,cov_d0rho/F,cov_phi02/F,cov_phi0rho/F,cov_rho2/F,cov_z02/F,cov_tandip2/F,circlefit_chi2_per_ndf/F,linefit_chi2_per_ndf/F,chi2/F,ndf/S,Cross1_ID/S,Cross2_ID/S,Cross3_ID/S,Cross4_ID/S,Cross5_ID/S,Cross6_ID/S,Cross7_ID/S,Cross8_ID/S,Cross9_ID/S,xb/F,yb/F,status/S}
schema : {RECFT::Particle/300/42}{pid/I,vt/F,beta/F,chi2pid/F,status/S}
schema : {TimeBasedTrkg::TBTracks/20600/36}{id/S,status/S,sector/B,c1_x/F,c1_y/F,c1_z/F,c1_ux/F,c1_uy/F,c1_uz/F,c3_x/F,c3_y/F,c3_z/F,c3_ux/F,c3_uy/F,c3_uz/F,t1_x/F,t1_y/F,t1_z/F,t1_px/F,t1_py/F,t1_pz/F,Vtx0_x/F,Vtx0_y/F,Vtx0_z/F,p0_x/F,p0_y/F,p0_z/F,Cross1_ID/S,Cross2_ID/S,Cross3_ID/S,q/B,pathlength/F,chi2/F,ndf/S}
schema : {DETECTOR::icpb/31000/51}{etc/F,ecc/F,tc/F,xc/F,yc/F}
schema : {RTPC::hits/1720/1}{trkID/I,id/I,time/F,x/F,y/F,z/F,tdiff/F}
schema : {RF::tdc/21700/12}{sector/B,layer/B,component/S,order/B,TDC/I}
schema : {FTCAL::clusters/21000/22}{size/S,id/S,x/F,y/F,z/F,widthX/F,widthY/F,radius/F,time/F,energy/F,maxEnergy/F,recEnergy/F}
schema : {HEADER::info/31000/1}{nrun/I,nevt/I,trigger/I,helicity/B,fc/F,fcg/F,stt/F,rastr1/S,rastr2/S}
schema : {RAW::scaler/20000/13}{crate/B,slot/B,channel/S,helicity/B,quartet/B,value/L}
schema : {BMTRec::Clusters/20100/22}{ID/S,sector/B,layer/B,size/S,ETot/F,seedE/F,seedStrip/I,centroid/F,centroidResidual/F,seedResidual/F,Hit1_ID/S,Hit2_ID/S,Hit3_ID/S,Hit4_ID/S,Hit5_ID/S,trkID/S}
schema : {TimeBasedTrkg::TBSegments/20600/33}{id/S,status/S,sector/B,superlayer/B,Cluster_ID/S,Hit1_ID/S,Hit2_ID/S,Hit3_ID/S,Hit4_ID/S,Hit5_ID/S,Hit6_ID/S,Hit7_ID/S,Hit8_ID/S,Hit9_ID/S,Hit10_ID/S,Hit11_ID/S,Hit12_ID/S,avgWire/F,fitChisqProb/F,fitSlope/F,fitSlopeErr/F,fitInterc/F,fitIntercErr/F,SegEndPoint1X/F,SegEndPoint1Z/F,SegEndPoint2X/F,SegEndPoint2Z/F,resiSum/F,timeSum/F,size/B}
schema : {RECHB::ForwardTagger/300/14}{index/S,pindex/S,detector/B,layer/B,energy/F,time/F,path/F,chi2/F,x/F,y/F,z/F,dx/F,dy/F,radius/F,size/S,status/S}
schema : {REC::Calorimeter/300/32}{index/S,pindex/S,detector/B,sector/B,layer/B,energy/F,time/F,path/F,chi2/F,x/F,y/F,z/F,hx/F,hy/F,hz/F,lu/F,lv/F,lw/F,du/F,dv/F,dw/F,m2u/F,m2v/F,m2w/F,m3u/F,m3v/F,m3w/F,status/S}
schema : {REC::CovMat/300/38}{index/S,pindex/S,C11/F,C12/F,C13/F,C14/F,C15/F,C22/F,C23/F,C24/F,C25/F,C33/F,C34/F,C35/F,C44/F,C45/F,C55/F}
schema : {RAW::epics/20000/15}{json/B}
schema : {REC::VertDoca/300/39}{index1/S,index2/S,x/F,y/F,z/F,x1/F,y1/F,z1/F,cx1/F,cy1/F,cz1/F,x2/F,y2/F,z2/F,cx2/F,cy2/F,cz2/F,r/F}
schema : {FTHODO::clusters/21100/22}{size/S,id/S,x/F,y/F,z/F,widthX/F,widthY/F,radius/F,time/F,energy/F}
schema : {RUN::scaler/10000/14}{fcupgated/F,fcup/F,livetime/F}
schema : {BAND::hits/22100/21}{id/S,sector/B,layer/B,component/S,meantimeTdc/F,meantimeFadc/F,difftimeTdc/F,difftimeFadc/F,adcLcorr/F,adcRcorr/F,tFadcLcorr/F,tFadcRcorr/F,tTdcLcorr/F,tTdcRcorr/F,x/F,y/F,z/F,ux/F,uy/F,uz/F}
schema : {FT::particles/20900/24}{id/S,charge/B,energy/F,cx/F,cy/F,cz/F,time/F,calID/S,hodoID/S,trkID/S}
schema : {ECAL::hits/20700/21}{id/S,status/S,sector/B,layer/B,strip/B,peakid/B,energy/F,time/F}
schema : {ECAL::clusters/20700/23}{id/S,status/S,sector/B,layer/B,x/F,y/F,z/F,energy/F,time/F,widthU/F,widthV/F,widthW/F,idU/B,idV/B,idW/B,coordU/I,coordV/I,coordW/I}
schema : {HitBasedTrkg::HBClusters/20600/22}{id/S,status/S,sector/B,superlayer/B,Hit1_ID/S,Hit2_ID/S,Hit3_ID/S,Hit4_ID/S,Hit5_ID/S,Hit6_ID/S,Hit7_ID/S,Hit8_ID/S,Hit9_ID/S,Hit10_ID/S,Hit11_ID/S,Hit12_ID/S,avgWire/F,fitChisqProb/F,fitSlope/F,fitSlopeErr/F,fitInterc/F,fitIntercErr/F,size/B}
schema : {REC::Track/300/36}{index/S,pindex/S,detector/B,sector/B,status/S,q/B,chi2/F,NDF/S}
schema : {FTOF::hbhits/21200/21}{id/S,status/S,trackid/S,sector/B,layer/B,component/S,energy/F,time/F,energy_unc/F,time_unc/F,x/F,y/F,z/F,x_unc/F,y_unc/F,z_unc/F,tx/F,ty/F,tz/F,adc_idx1/S,adc_idx2/S,tdc_idx1/S,tdc_idx2/S,pathLength/F,pathLengthThruBar/F}
schema : {RECHB::Event/300/10}{category/L,topology/L,beamCharge/F,liveTime/D,startTime/F,RFTime/F,helicity/B,helicityRaw/B,procTime/F}
schema : {RTPC::adc/21900/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S}
schema : {FTCAL::adc/21000/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S}
schema : {CTOF::rawhits/20400/20}{id/S,status/S,component/S,energy_up/F,energy_down/F,time_up/F,time_down/F,energy_up_unc/F,energy_down_unc/F,time_up_unc/F,time_down_unc/F}
schema : {CND::adc/20300/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S}
schema : {RICH::ringCher/21800/34}{id/S,hindex/S,pindex/B,pmt/S,anode/B,time/F,apath/F,atime/F,aEtaC/F,tpath/F,ttime/F,tEtaC/F,nrfl/B,1rfl/S}
schema : {FTOF::hits/21200/31}{id/S,status/S,trackid/S,sector/B,layer/B,component/S,energy/F,time/F,energy_unc/F,time_unc/F,x/F,y/F,z/F,x_unc/F,y_unc/F,z_unc/F,tx/F,ty/F,tz/F,adc_idx1/S,adc_idx2/S,tdc_idx1/S,tdc_idx2/S,pathLength/F,pathLengthThruBar/F}
schema : {FMTRec::Clusters/20800/22}{ID/S,sector/B,layer/B,size/S,ETot/F,seedE/F,seedStrip/I,centroid/F,centroidResidual/F,seedResidual/F,Hit1_ID/S,Hit2_ID/S,Hit3_ID/S,Hit4_ID/S,Hit5_ID/S,trkID/S}
schema : {HEL::adc/22000/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S}
schema : {REC::ForwardTagger/300/34}{index/S,pindex/S,detector/B,layer/B,energy/F,time/F,path/F,chi2/F,x/F,y/F,z/F,dx/F,dy/F,radius/F,size/S,status/S}
schema : {FTTRK::adc/21300/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S,integral/I,timestamp/L}
schema : {DETECTOR::ccpb/31000/33}{sector/B,nphe/F,time/F,path/F}
schema : {FTOF::rawhits/21200/20}{id/S,status/S,sector/B,layer/B,component/S,energy_left/F,energy_right/F,time_left/F,time_right/F,energy_left_unc/F,energy_right_unc/F,time_left_unc/F,time_right_unc/F}
schema : {RECHB::TrackCross/300/17}{index/S,pindex/S,detector/B,sector/B,layer/B,c_x/F,c_y/F,c_z/F,c_ux/F,c_uy/F,c_uz/F,status/S}
schema : {DETECTOR::scpb/31000/32}{sector/B,paddle/B,edep/F,time/F,path/F}
schema : {FTHODO::hits/21100/21}{sector/B,layer/B,component/S,x/F,y/F,z/F,energy/F,time/F,hitID/S,clusterID/S}
schema : {RECFT::Event/300/41}{category/L,startTime/F}
schema : {CTOF::adc/20400/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S}
schema : {EVENT::detector/31000/22}{scsector/I,scpaddle/I,ecsector/I,ccnphe/F,sctime/F,scpath/F,ectime/F,ecpath/F,ecin/F,ecout/F,ectot/F,ecu/F,ecv/F,ecw/F}
schema : {DC::doca/20600/14}{LR/B,doca/F,sdoca/F,time/F,stime/F}
schema : {HTCC::tdc/21500/12}{sector/B,layer/B,component/S,order/B,TDC/I}
schema : {HEL::online/22000/13}{helicity/B,helicityRaw/B}
schema : {REC::Event/300/30}{category/L,topology/L,beamCharge/F,liveTime/D,startTime/F,RFTime/F,helicity/B,helicityRaw/B,procTime/F}
schema : {REC::Particle/300/31}{pid/I,px/F,py/F,pz/F,vx/F,vy/F,vz/F,vt/F,charge/B,beta/F,chi2pid/F,status/S}
schema : {REC::Traj/300/40}{pindex/S,index/S,detector/B,layer/B,x/F,y/F,z/F,cx/F,cy/F,cz/F,path/F}
schema : {FTOF::tdc/21200/12}{sector/B,layer/B,component/S,order/B,TDC/I}
schema : {FTCAL::hits/21000/21}{idx/B,idy/B,x/F,y/F,z/F,energy/F,time/F,hitID/S,clusterID/S}
schema : {HitBasedTrkg::HBSegments/20600/23}{id/S,status/S,sector/B,superlayer/B,Cluster_ID/S,Hit1_ID/S,Hit2_ID/S,Hit3_ID/S,Hit4_ID/S,Hit5_ID/S,Hit6_ID/S,Hit7_ID/S,Hit8_ID/S,Hit9_ID/S,Hit10_ID/S,Hit11_ID/S,Hit12_ID/S,avgWire/F,fitChisqProb/F,fitSlope/F,fitSlopeErr/F,fitInterc/F,fitIntercErr/F,SegEndPoint1X/F,SegEndPoint1Z/F,SegEndPoint2X/F,SegEndPoint2Z/F,size/B}
schema : {FMTRec::Hits/20800/21}{ID/S,sector/B,layer/B,strip/I,fitResidual/F,trkingStat/I,clusterID/S,trkID/S}
schema : {BAND::tdc/22100/12}{sector/B,layer/B,component/S,order/B,TDC/I}
schema : {RF::adc/21700/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S}
schema : {FMTRec::Crosses/20800/25}{ID/S,sector/B,region/B,x/F,y/F,z/F,err_x/F,err_y/F,err_z/F,ux/F,uy/F,uz/F,Cluster1_ID/S,Cluster2_ID/S,trkID/S}
schema : {ECAL::tdc/20700/12}{sector/B,layer/B,component/S,order/B,TDC/I}
schema : {MC::Particle/40/2}{pid/I,px/F,py/F,pz/F,vx/F,vy/F,vz/F,vt/F}
schema : {RICH::tdc/21800/12}{sector/B,layer/B,component/S,order/B,TDC/I}
schema : {LTCC::tdc/21600/12}{sector/B,layer/B,component/S,order/B,TDC/I}
schema : {ECAL::moments/20700/25}{distU/F,distV/F,distW/F,m1u/F,m1v/F,m1w/F,m2u/F,m2v/F,m2w/F,m3u/F,m3v/F,m3w/F}
schema : {RUN::trigger/10000/13}{id/I,trigger/I}
schema : {EVENT::particle/31000/21}{status/B,charge/B,pid/I,mass/F,px/F,py/F,pz/F,vx/F,vy/F,vz/F,dcstat/B,ecstat/B,scstat/B,ccstat/B,lcstat/B}
schema : {HitBasedTrkg::HBHits/20600/21}{id/S,status/S,sector/B,superlayer/B,layer/B,wire/S,TDC/I,trkDoca/F,docaError/F,LR/B,LocX/F,LocY/F,X/F,Z/F,B/F,TProp/F,TFlight/F,clusterID/S,trkID/B}
schema : {TimeBasedTrkg::TBHits/20600/31}{id/S,status/S,sector/B,superlayer/B,layer/B,wire/S,TDC/I,doca/F,docaError/F,trkDoca/F,timeResidual/F,fitResidual/F,LR/B,X/F,Z/F,B/F,Alpha/F,TProp/F,TFlight/F,T0/F,TStart/F,clusterID/S,trkID/B,time/F,beta/F,tBeta/F}
schema : {CTOF::hits/20400/21}{id/S,status/S,trkID/S,sector/B,layer/B,component/S,energy/F,time/F,energy_unc/F,time_unc/F,x/F,y/F,z/F,x_unc/F,y_unc/F,z_unc/F,tx/F,ty/F,tz/F,adc_idx1/S,adc_idx2/S,tdc_idx1/S,tdc_idx2/S,pathLength/F,pathLengthThruBar/F}
schema : {RECHB::Particle/300/11}{pid/I,px/F,py/F,pz/F,vx/F,vy/F,vz/F,vt/F,charge/B,beta/F,chi2pid/F,status/S}
schema : {RAW::tdc/20000/12}{crate/B,slot/B,channel/S,order/B,TDC/I}
schema : {RICH::photons/21800/33}{id/S,type/S,hit_index/S,hadron_index/S,start_time/F,analytic_the/F,analytic_phi/F,analytic_path/F,analytic_time/F,analytic_EtaC/F,analytic_aeron/F,analytic_elpr/F,analytic_pipr/F,analytic_kpr/F,analytic_prpr/F,analytic_bgpr/F,traced_the/F,traced_phi/F,traced_hitx/F,traced_hity/F,traced_hitz/F,traced_path/F,traced_time/F,traced_nrfl/S,traced_nrfr/S,traced_1rfl/S,traced_EtaC/F,traced_aeron/F,traced_elpr/F,traced_pipr/F,traced_kpr/F,traced_prpr/F,traced_bgpr/F}
schema : {HEL::flip/22000/12}{run/I,event/I,timestamp/L,helicity/B,helicityRaw/B,pair/B,pattern/B,status/B}
schema : {TimeBasedTrkg::Trajectory/20600/53}{id/S,detector/B,layer/B,x/F,y/F,z/F,tx/F,ty/F,tz/F,B/F,path/F}
schema : {DETECTOR::ecpb/31000/31}{sector/B,etot/F,ein/F,eout/F,time/F,path/F,x/F,y/F,z/F}
schema : {CND::hits/20300/21}{id/S,status/S,trkID/S,sector/B,layer/B,component/S,energy/F,time/F,energy_unc/F,time_unc/F,x/F,y/F,z/F,x_unc/F,y_unc/F,z_unc/F,tx/F,ty/F,tz/F,tlength/F,pathlength/F,indexLadc/S,indexRadc/S,indexLtdc/S,indexRtdc/S}

*****>>>>> compiled with c++11 support.
---> resizing internal compressed buffer size to from 6780 to 3803364
 resizing internal buffer from 5468 to 8383230
---> resizing internal compressed buffer size to from 3803364 to 3815664
 resizing internal buffer from 8384718 to 8387613
---> resizing internal compressed buffer size to from 3815664 to 3828084
---> resizing internal compressed buffer size to from 3828084 to 3859280
ifarm1802.jlab.org> pwd
/w/hallb-scifs17exp/clas/claseg4/adhikari/Bonus12/Gemc/hipo4cpp/hipo/examples/root/kuhn
ifarm1802.jlab.org>
adhikari@ifarm1802.jlab.org> ./testingdictionary.exe data/out_ep_34118_20_15kEvs.hipo | grep -in rtpc
38:schema : {RTPC::tracks/1720/2}{trkID/I,px/F,py/F,pz/F,vz/F,theta/F,phi/F,nhits/I,path/F,dedx/F}
40:schema : {RTPC::pos/21900/14}{step/I,time/F,energy/F,posx/F,posy/F,posz/F,phi/F,tid/I}
96:schema : {RTPC::hits/1720/1}{trkID/I,id/I,time/F,x/F,y/F,z/F,tdiff/F}
118:schema : {RTPC::adc/21900/11}{sector/B,layer/B,component/S,order/B,ADC/I,time/F,ped/S}
adhikari@ifarm1802.jlab.org> pwd
/w/hallb-scifs17exp/clas/claseg4/adhikari/Bonus12/Gemc/hipo4cpp/hipo/examples/root/kuhn
adhikari@ifarm1802.jlab.org>

==========================================================================================
==========================================================================================
From bank.h in Bonus12/Gemc/hipo4cpp/hipo/hipo4


        hipo::schema  &getSchema() { return bankSchema;}

        int    getRows()  const noexcept{ return bankRows;}
        void   setRows(   int rows);
        int    getInt(    int item, int index) const noexcept;
        int    getShort(  int item, int index) const noexcept;
        int    getByte(   int item, int index) const noexcept;
        float  getFloat(  int item, int index) const noexcept;
        double getDouble( int item, int index) const noexcept;
        long   getLong(   int item, int index) const noexcept;

        int    getInt(    const char *name, int index) const noexcept;
        int    getShort(  const char *name, int index) const noexcept;
        int    getByte(   const char *name, int index) const noexcept;
        float  getFloat(  const char *name, int index) const noexcept;
        double getDouble( const char *name, int index) const noexcept;
        long   getLong(   const char *name, int index) const noexcept;

        void    putInt(    const char *name, int index, int32_t value);
        void    putShort(  const char *name, int index, int16_t value);
        void    putByte(   const char *name, int index, int8_t value);
        void    putFloat(  const char *name, int index, float value);
        void    putDouble( const char *name, int index, double value);
        void    putLong(   const char *name, int index, int64_t value);

