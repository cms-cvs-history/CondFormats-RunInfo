#include "CondFormats/RunInfo/interface/LuminosityInfo.h"
//#include "FWCore/Utilities/Exception.h"

lumi::LuminosityInfo::LuminosityInfo(){
  m_bx.reserve(lumi::BXMAX*LUMIALGOMAX);
  m_summaryinfo.reserve(lumi::LUMIALGOMAX);
  m_hltinfo.reserve(100);//hardcoded guess
}
int
lumi::LuminosityInfo::lumisectionID()const{
  return m_sectionid;
}
float
lumi::LuminosityInfo::deadTimeNormalization()const{
  return m_deadtime_normalization;
}
size_t
lumi::LuminosityInfo::nBunchCrossing()const{
  return m_bx.size()/lumi::LUMIALGOMAX;
}
size_t
lumi::LuminosityInfo::nHLTtrigger()const{
  return m_hltinfo.size();
}
lumi::HLTIterator 
lumi::LuminosityInfo::hltBegin()const{
  return m_hltinfo.begin();
}
lumi::HLTIterator
lumi::LuminosityInfo::hltEnd()const{
  return m_hltinfo.end();
}
lumi::LumiAverage
lumi::LuminosityInfo::lumiAverage(const lumi::LumiAlgoType lumialgotype)const{
  return m_summaryinfo.at(lumialgotype);
}
const lumi::BunchCrossingInfo 
lumi::LuminosityInfo::bunchCrossingInfo( const int BXIndex,
				  const LumiAlgoType lumialgotype )const{
  int realIdx=BXIndex-lumi::BXMIN+lumialgotype*BXMAX;
  return m_bx.at(realIdx);
}
lumi::BunchCrossingIterator 
lumi::LuminosityInfo::bunchCrossingBegin( const LumiAlgoType lumialgotype )const{
  return m_bx.begin()+lumialgotype*BXMAX;
}
lumi::BunchCrossingIterator 
lumi::LuminosityInfo::bunchCrossingEnd( const LumiAlgoType lumialgotype )const{
  return m_bx.end()-(lumi::BXMAX)*lumialgotype;
}
void
lumi::LuminosityInfo::setLumiSectionId(int sectionid){
  m_sectionid=sectionid;
}
void 
lumi::LuminosityInfo::setHLTData(const std::vector<HLTInfo>& hltdetail){
  std::copy(hltdetail.begin(),hltdetail.end(),std::back_inserter(m_hltinfo));
}
void 
lumi::LuminosityInfo::setDeadtimeNormalization(float dtimenorm){
  m_deadtime_normalization=dtimenorm;
}
void
lumi::LuminosityInfo::setLumiAverage(const LumiAverage& avg,const LumiAlgoType algotype){
  m_summaryinfo[algotype]=avg;
}
void 
lumi::LuminosityInfo::setBunchCrossingData(const std::vector<BunchCrossingInfo>& BXs,const LumiAlgoType algotype){
  std::copy(BXs.begin(),BXs.begin()+lumi::BXMAX,std::back_inserter(m_bx));
}

