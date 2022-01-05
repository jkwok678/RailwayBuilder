#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include <QFile>
#include <QIODevice>
#include "map.h"
#include "element.h"
#include "track.h"

TEST(MapSavingQStringTest, straightTrackListToQString) {
    Map *map = new Map();
    map->createAddStraightTrack(StraightType::STRAIGHTH,1,2);
    EXPECT_EQ(map->straightTrackListToQStringForSaving().toStdString(),"SH,1,2,200,100,0,0,0\n");
	std::shared_ptr<StraightTrack> straightOne = map->getStraightTrackAt(1,2);
	straightOne->setPlatform1(true);
	EXPECT_EQ(map->straightTrackListToQStringForSaving().toStdString(),"SH,1,2,200,100,1,0,0\n");
	straightOne->setPlatform2(true);
	EXPECT_EQ(map->straightTrackListToQStringForSaving().toStdString(),"SH,1,2,200,100,1,1,0\n");
	straightOne->setPlatform1(false);
	EXPECT_EQ(map->straightTrackListToQStringForSaving().toStdString(),"SH,1,2,200,100,0,1,0\n");
	straightOne->setPlatform2(false);
	straightOne->addLevelCrossing();
	EXPECT_EQ(map->straightTrackListToQStringForSaving().toStdString(),"SH,1,2,200,100,0,0,1\n");
	straightOne->removeLevelCrossing();
    map->createAddStraightTrack(StraightType::STRAIGHTV,100,6);
    EXPECT_EQ(map->straightTrackListToQStringForSaving().toStdString(),"SH,1,2,200,100,0,0,0\nSV,100,6,200,100,0,0,0\n");
    map->createAddStraightTrack(StraightType::STRAIGHTLEFTUP,542671,-232342);
    EXPECT_EQ(map->straightTrackListToQStringForSaving().toStdString(),"SH,1,2,200,100,0,0,0\nSV,100,6,200,100,0,0,0\nSLU,542671,-232342,200,100,0,0,0\n");
}

TEST(MapSavingQStringTest, directedTrackListToQString) {
    Map *map = new Map();
    map->createAddDirectedTrack(DirectedType::DIRECTEDLEFT,1,2);
    EXPECT_EQ(map->directedTrackListToQStringForSaving().toStdString(),"DL,1,2,200,100,0,0\n");
    map->createAddDirectedTrack(DirectedType::DIRECTEDLEFTUP,100,6);
    EXPECT_EQ(map->directedTrackListToQStringForSaving().toStdString(),"DL,1,2,200,100,0,0\nDLU,100,6,200,100,0,0\n");
    map->createAddDirectedTrack(DirectedType::DIRECTEDRIGHTDOWN,542671,-232342);
	std::shared_ptr<DirectedTrack> directedOne = map->getDirectedTrackAt(1,2);
	std::shared_ptr<DirectedTrack> directedTwo = map->getDirectedTrackAt(100,6);
    EXPECT_EQ(map->directedTrackListToQStringForSaving().toStdString(),"DL,1,2,200,100,0,0\nDLU,100,6,200,100,0,0\nDRD,542671,-232342,200,100,0,0\n");
	directedOne->setPlatform1(true);
	directedTwo->setPlatform2(true);
	EXPECT_EQ(map->directedTrackListToQStringForSaving().toStdString(),"DL,1,2,200,100,1,0\nDLU,100,6,200,100,0,1\nDRD,542671,-232342,200,100,0,0\n");
}

TEST(MapSavingQStringTest, curvedTrackListToQString) {
    Map *map = new Map();
    map->createAddCurvedTrack(CurvedType::CURVE1,1,2);
    EXPECT_EQ(map->curvedTrackListToQStringForSaving().toStdString(),"C1,1,2,200,100\n");
    map->createAddCurvedTrack(CurvedType::CURVE6,100,6);
    EXPECT_EQ(map->curvedTrackListToQStringForSaving().toStdString(),"C1,1,2,200,100\nC6,100,6,200,100\n");
    map->createAddCurvedTrack(CurvedType::TIGHTCURVE4,542671,-232342);
    EXPECT_EQ(map->curvedTrackListToQStringForSaving().toStdString(),"C1,1,2,200,100\nC6,100,6,200,100\nTC4,542671,-232342,200,100\n");
}

TEST(MapSavingQStringTest, linkedTrackListToQString) {
	Map *map = new Map();
	map->createAddLinkedTrack(LinkedType::LINKRIGHT,1,2);
	EXPECT_EQ(map->linkedTrackListToQStringForSaving().toStdString(),"LR,1,2,200,100,0\n");
	map->createAddLinkedTrack(LinkedType::LINKUP,100,6);
	EXPECT_EQ(map->linkedTrackListToQStringForSaving().toStdString(),"LR,1,2,200,100,0\nLU,100,6,200,100,0\n");
	std::shared_ptr<LinkedTrack> linkedOne = map->getLinkedTrackAt(1,2);
	std::shared_ptr<LinkedTrack> linkedTwo = map->getLinkedTrackAt(100,6);
	linkedOne->setOtherLinkedTrack(linkedTwo);
	linkedTwo->setOtherLinkedTrack(linkedOne);
	EXPECT_EQ(map->linkedTrackListToQStringForSaving().toStdString(),"LR,1,2,200,100,1,LU,100,6,200,100\nLU,100,6,200,100,1,LR,1,2,200,100\n");
	map->disconnectLinkedTrack(linkedOne,linkedTwo);
	map->createAddLinkedTrack(LinkedType::LINKLEFTDOWN,542671,-232342);
	EXPECT_EQ(map->linkedTrackListToQStringForSaving().toStdString(),"LR,1,2,200,100,0\nLU,100,6,200,100,0\nLLD,542671,-232342,200,100,0\n");
}

TEST(MapSavingQStringTest, exitTrackListToQString) {
	Map *map = new Map();
	map->createAddExitTrack(ExitType::EXITLEFT,1,2);
	EXPECT_EQ(map->exitTrackListToQStringForSaving().toStdString(),"EL,1,2,200,100\n");
	map->createAddExitTrack(ExitType::EXITRIGHTDOWN,100,6);
	EXPECT_EQ(map->exitTrackListToQStringForSaving().toStdString(),"EL,1,2,200,100\nERD,100,6,200,100\n");
	map->createAddExitTrack(ExitType::EXITUP,542671,-232342);
	EXPECT_EQ(map->exitTrackListToQStringForSaving().toStdString(),"EL,1,2,200,100\nERD,100,6,200,100\nEU,542671,-232342,200,100\n");
}

TEST(MapSavingQStringTest, bufferTrackListToQString) {
	Map *map = new Map();
	map->createAddBufferTrack(BufferType::BUFFERLEFT,1,2);
	EXPECT_EQ(map->bufferTrackListToQStringForSaving().toStdString(),"BL,1,2,200,100,0,0\n");
	map->createAddBufferTrack(BufferType::BUFFERRIGHTDOWN,100,6);
	EXPECT_EQ(map->bufferTrackListToQStringForSaving().toStdString(),"BL,1,2,200,100,0,0\nBRD,100,6,200,100,0,0\n");
	std::shared_ptr<BufferTrack> bufferOne = map->getBufferTrackAt(1,2);
	std::shared_ptr<BufferTrack> bufferTwo = map->getBufferTrackAt(100,6);
	bufferOne->setPlatform1(true);
	bufferTwo->setPlatform2(true);
	EXPECT_EQ(map->bufferTrackListToQStringForSaving().toStdString(),"BL,1,2,200,100,1,0\nBRD,100,6,200,100,0,1\n");
	bufferOne->setPlatform1(false);
	bufferTwo->setPlatform2(false);
	map->createAddBufferTrack(BufferType::BUFFERUP,542671,-232342);
	EXPECT_EQ(map->bufferTrackListToQStringForSaving().toStdString(),"BL,1,2,200,100,0,0\nBRD,100,6,200,100,0,0\nBU,542671,-232342,200,100,0,0\n");
}

TEST(MapSavingQStringTest, signalTrackListToQString) {
	Map *map = new Map();
	map->createAddSignalTrack(SignalType::SIGNALLEFT,4,1,2);
	EXPECT_EQ(map->signalTrackListToQStringForSaving().toStdString(),"SIGL,4,1,2,200,100,0,0\n");
	map->createAddSignalTrack(SignalType::SIGNALRIGHTDOWN,4,100,6);
	EXPECT_EQ(map->signalTrackListToQStringForSaving().toStdString(),"SIGL,4,1,2,200,100,0,0\nSIGRD,4,100,6,200,100,0,0\n");
	std::shared_ptr<SignalTrack> signalOne = map->getSignalTrackAt(1,2);
	std::shared_ptr<SignalTrack> signalTwo = map->getSignalTrackAt(100,6);
	signalOne->setPlatform1(true);
	signalTwo->setPlatform2(true);
	EXPECT_EQ(map->signalTrackListToQStringForSaving().toStdString(),"SIGL,4,1,2,200,100,1,0\nSIGRD,4,100,6,200,100,0,1\n");
	signalOne->setPlatform1(false);
	signalTwo->setPlatform2(false);
	map->createAddSignalTrack(SignalType::SIGNALUP,4,542671,-232342);
	EXPECT_EQ(map->signalTrackListToQStringForSaving().toStdString(),"SIGL,4,1,2,200,100,0,0\nSIGRD,4,100,6,200,100,0,0\nSIGU,4,542671,-232342,200,100,0,0\n");
}

TEST(MapSavingQStringTest, bridgeUnderpassTrackListToQString) {
	Map *map = new Map();
	map->createAddBridgeUnderpassTrack(BridgeUnderpassType::BRIDGE1,1,2);
	EXPECT_EQ(map->bridgeUnderpassTrackListToQStringForSaving().toStdString(),"BR1,1,2,200,100,0,0\n");
	map->createAddBridgeUnderpassTrack(BridgeUnderpassType::BRIDGE2,100,6);
	EXPECT_EQ(map->bridgeUnderpassTrackListToQStringForSaving().toStdString(),"BR1,1,2,200,100,0,0\nBR2,100,6,200,100,0,0\n");
	map->createAddBridgeUnderpassTrack(BridgeUnderpassType::UNDERPASS2,542671,-232342);
	EXPECT_EQ(map->bridgeUnderpassTrackListToQStringForSaving().toStdString(),"BR1,1,2,200,100,0,0\nBR2,100,6,200,100,0,0\nUP2,542671,-232342,200,100,0,0\n");
	std::shared_ptr<BridgeUnderpassTrack> bridgeOne = map->getBridgeUnderpassTrack(1,2);
	std::shared_ptr<BridgeUnderpassTrack> bridgeTwo = map->getBridgeUnderpassTrack(100,6);
	std::shared_ptr<BridgeUnderpassTrack> underpassTwo = map->getBridgeUnderpassTrack(542671,-232342);
	bridgeOne->setPlatform1(true);
	bridgeTwo->setPlatform2(true);
	underpassTwo->setPlatform2(true);
	EXPECT_EQ(map->bridgeUnderpassTrackListToQStringForSaving().toStdString(),"BR1,1,2,200,100,1,0\nBR2,100,6,200,100,0,1\nUP2,542671,-232342,200,100,0,1\n");
}

TEST(MapSavingQStringTest, switchTrackListToQString) {
	Map *map = new Map();
	map->createAddSwitchTrack(SwitchType::SWITCH1,1,2);
	EXPECT_EQ(map->switchTrackListToQStringForSaving().toStdString(),"SW1,1,2,200,100,200,100,0,0\n");
	map->createAddSwitchTrack(SwitchType::SWITCH15,100,6);
	EXPECT_EQ(map->switchTrackListToQStringForSaving().toStdString(),"SW1,1,2,200,100,200,100,0,0\nSW15,100,6,200,100,200,100,0,0\n");
	map->createAddSwitchTrack(SwitchType::SWITCHTIGHT5,542671,-232342);
	EXPECT_EQ(map->switchTrackListToQStringForSaving().toStdString(),"SW1,1,2,200,100,200,100,0,0\nSW15,100,6,200,100,200,100,0,0\nSWT5,542671,-232342,200,100,200,100,0,0\n");
	map->createAddSwitchTrack(SwitchType::SWITCHSPLIT3,2,-3);
	EXPECT_EQ(map->switchTrackListToQStringForSaving().toStdString(),"SW1,1,2,200,100,200,100,0,0\nSW15,100,6,200,100,200,100,0,0\nSWT5,542671,-232342,200,100,200,100,0,0\nSWS3,2,-3,200,100,200,100,0,0\n");
}

TEST(MapSavingQStringTest, crossoverTrackListToQString) {
	Map *map = new Map();
	map->createAddCrossoverTrack(CrossoverType::CROSSOVER1,1,2);
	EXPECT_EQ(map->crossoverTrackListToQStringForSaving().toStdString(),"CR1,1,2,200,100,200,100\n");
	map->createAddCrossoverTrack(CrossoverType::CROSSOVER3,100,6);
	EXPECT_EQ(map->crossoverTrackListToQStringForSaving().toStdString(),"CR1,1,2,200,100,200,100\nCR3,100,6,200,100,200,100\n");
	map->createAddCrossoverTrack(CrossoverType::CROSSOVER6,542671,-232342);
	EXPECT_EQ(map->crossoverTrackListToQStringForSaving().toStdString(),"CR1,1,2,200,100,200,100\nCR3,100,6,200,100,200,100\nCR6,542671,-232342,200,100,200,100\n");
}

TEST(MapSavingQStringTest, flyoverTrackListToQString) {
	Map *map = new Map();
	map->createAddFlyoverTrack(FlyoverType::FLYOVER1,1,2);
	EXPECT_EQ(map->flyoverTrackListToQStringForSaving().toStdString(),"F1,1,2,200,100,200,100\n");
	map->createAddFlyoverTrack(FlyoverType::FLYOVER6,100,6);
	EXPECT_EQ(map->flyoverTrackListToQStringForSaving().toStdString(),"F1,1,2,200,100,200,100\nF6,100,6,200,100,200,100\n");
	map->createAddFlyoverTrack(FlyoverType::FLYOVER11,542671,-232342);
	EXPECT_EQ(map->flyoverTrackListToQStringForSaving().toStdString(),"F1,1,2,200,100,200,100\nF6,100,6,200,100,200,100\nF11,542671,-232342,200,100,200,100\n");
}

TEST(MapSavingQStringTest, namedLocationListToQString) {
	Map *map = new Map();
	map->createAddNamedLocation(1,1);
	EXPECT_EQ(map->namedLocationListToQStringForSaving().toStdString(),"1,1\n");
	map->createAddNamedLocation(2,2);
	EXPECT_EQ(map->namedLocationListToQStringForSaving().toStdString(),"1,1\n2,2\n");
	map->createAddNamedLocation(3,3);
	EXPECT_EQ(map->namedLocationListToQStringForSaving().toStdString(),"1,1\n2,2\n3,3\n");
}

TEST(MapSavingQStringTest, concourseToQString) {
	Map *map = new Map();
	map->createAddConcourse(1,1);
	EXPECT_EQ(map->concourseListToQStringForSaving().toStdString(),"1,1\n");
	map->createAddConcourse(2,2);
	EXPECT_EQ(map->concourseListToQStringForSaving().toStdString(),"1,1\n2,2\n");
	map->createAddConcourse(3,3);
	EXPECT_EQ(map->concourseListToQStringForSaving().toStdString(),"1,1\n2,2\n3,3\n");
}

TEST(MapGetAllElementFromLocationTest, getStraightTrackFromLocation) {
	Map *map = new Map();
	map->createAddStraightTrack(StraightType::STRAIGHTH,1,1);
	std::shared_ptr<StraightTrack> track1 = map->getStraightTrackAt(1,1);
	EXPECT_EQ(track1->getStraightType(),StraightType::STRAIGHTH);
	EXPECT_EQ(track1->getLocationX(),1);
	EXPECT_EQ(track1->getLocationY(),1);
	map->createAddStraightTrack(StraightType::STRAIGHTV,-1,-1);
	std::shared_ptr<StraightTrack> track2 = map->getStraightTrackAt(-1,-1);
	EXPECT_EQ(track2->getStraightType(),StraightType::STRAIGHTV);
	EXPECT_EQ(track2->getLocationX(),-1);
	EXPECT_EQ(track2->getLocationY(),-1);
}

TEST(MapGetAllElementFromLocationTest, getDirectedTrackFromLocation) {
	Map *map = new Map();
	map->createAddDirectedTrack(DirectedType::DIRECTEDLEFT,1,1);
	std::shared_ptr<DirectedTrack> track1 = map->getDirectedTrackAt(1,1);
	EXPECT_EQ(track1->getDirectType(),DirectedType::DIRECTEDLEFT);
	EXPECT_EQ(track1->getLocationX(),1);
	EXPECT_EQ(track1->getLocationY(),1);
	map->createAddDirectedTrack(DirectedType::DIRECTEDRIGHT,-1,-1);
	std::shared_ptr<DirectedTrack> track2 = map->getDirectedTrackAt(-1,-1);
	EXPECT_EQ(track2->getDirectType(),DirectedType::DIRECTEDRIGHT);
	EXPECT_EQ(track2->getLocationX(),-1);
	EXPECT_EQ(track2->getLocationY(),-1);
}

TEST(MapGetAllElementFromLocationTest, getCurvedTrackFromLocation) {
	Map *map = new Map();
	map->createAddCurvedTrack(CurvedType::CURVE1,1,1);
	std::shared_ptr<CurvedTrack> track1 = map->getCurvedTrackAt(1,1);
	EXPECT_EQ(track1->getCurvedType(),CurvedType::CURVE1);
	EXPECT_EQ(track1->getLocationX(),1);
	EXPECT_EQ(track1->getLocationY(),1);
	map->createAddCurvedTrack(CurvedType::CURVE8,-1,-1);
	std::shared_ptr<CurvedTrack> track2 = map->getCurvedTrackAt(-1,-1);
	EXPECT_EQ(track2->getCurvedType(),CurvedType::CURVE8);
	EXPECT_EQ(track2->getLocationX(),-1);
	EXPECT_EQ(track2->getLocationY(),-1);
}

TEST(MapGetAllElementFromLocationTest, getLinkedTrackFromLocation) {
	Map *map = new Map();
	map->createAddLinkedTrack(LinkedType::LINKLEFT,1,1);
	std::shared_ptr<LinkedTrack> track1 = map->getLinkedTrackAt(1,1);
	EXPECT_EQ(track1->getLinkedType(),LinkedType::LINKLEFT);
	EXPECT_EQ(track1->getLocationX(),1);
	EXPECT_EQ(track1->getLocationY(),1);
	map->createAddLinkedTrack(LinkedType::LINKRIGHT,-1,-1);
	std::shared_ptr<LinkedTrack> track2 = map->getLinkedTrackAt(-1,-1);
	EXPECT_EQ(track2->getLinkedType(),LinkedType::LINKRIGHT);
	EXPECT_EQ(track2->getLocationX(),-1);
	EXPECT_EQ(track2->getLocationY(),-1);
}

TEST(MapGetAllElementFromLocationTest, getExitTrackFromLocation) {
	Map *map = new Map();
	map->createAddExitTrack(ExitType::EXITLEFT,1,1);
	std::shared_ptr<ExitTrack> track1 = map->getExitTrackAt(1,1);
	EXPECT_EQ(track1->getExitType(),ExitType::EXITLEFT);
	EXPECT_EQ(track1->getLocationX(),1);
	EXPECT_EQ(track1->getLocationY(),1);
	map->createAddExitTrack(ExitType::EXITRIGHT,-1,-1);
	std::shared_ptr<ExitTrack> track2 = map->getExitTrackAt(-1,-1);
	EXPECT_EQ(track2->getExitType(),ExitType::EXITRIGHT);
	EXPECT_EQ(track2->getLocationX(),-1);
	EXPECT_EQ(track2->getLocationY(),-1);
}

TEST(MapGetAllElementFromLocationTest, getBufferTrackFromLocation) {
	Map *map = new Map();
	map->createAddBufferTrack(BufferType::BUFFERLEFT,1,1);
	std::shared_ptr<BufferTrack> track1 = map->getBufferTrackAt(1,1);
	EXPECT_EQ(track1->getBufferType(),BufferType::BUFFERLEFT);
	EXPECT_EQ(track1->getLocationX(),1);
	EXPECT_EQ(track1->getLocationY(),1);
	map->createAddBufferTrack(BufferType::BUFFERRIGHT,-1,-1);
	std::shared_ptr<BufferTrack> track2 = map->getBufferTrackAt(-1,-1);
	EXPECT_EQ(track2->getBufferType(),BufferType::BUFFERRIGHT);
	EXPECT_EQ(track2->getLocationX(),-1);
	EXPECT_EQ(track2->getLocationY(),-1);
}

TEST(MapGetAllElementFromLocationTest, getSignalTrackFromLocation) {
	Map *map = new Map();
	map->createAddSignalTrack(SignalType::SIGNALLEFT,4,1,1);
	std::shared_ptr<SignalTrack> track1 = map->getSignalTrackAt(1,1);
	EXPECT_EQ(track1->getSignalType(),SignalType::SIGNALLEFT);
	EXPECT_EQ(track1->getLocationX(),1);
	EXPECT_EQ(track1->getLocationY(),1);
	map->createAddSignalTrack(SignalType::SIGNALRIGHT,4,-1,-1);
	std::shared_ptr<SignalTrack> track2 = map->getSignalTrackAt(-1,-1);
	EXPECT_EQ(track2->getSignalType(),SignalType::SIGNALRIGHT);
	EXPECT_EQ(track2->getLocationX(),-1);
	EXPECT_EQ(track2->getLocationY(),-1);
}

TEST(MapGetAllElementFromLocationTest, getBridgeUnderpassTrackFromLocation) {
	Map *map = new Map();
	map->createAddBridgeUnderpassTrack(BridgeUnderpassType::BRIDGE1,1,1);
	std::shared_ptr<BridgeUnderpassTrack> track1 = map->getBridgeUnderpassTrack(1,1);
	EXPECT_EQ(track1->getBridgeUnderpassType(),BridgeUnderpassType::BRIDGE1);
	EXPECT_EQ(track1->getLocationX(),1);
	EXPECT_EQ(track1->getLocationY(),1);
	map->createAddBridgeUnderpassTrack(BridgeUnderpassType::UNDERPASS1,-1,-1);
	std::shared_ptr<BridgeUnderpassTrack> track2 = map->getBridgeUnderpassTrack(-1,-1);
	EXPECT_EQ(track2->getBridgeUnderpassType(),BridgeUnderpassType::UNDERPASS1);
	EXPECT_EQ(track2->getLocationX(),-1);
	EXPECT_EQ(track2->getLocationY(),-1);
}

TEST(MapGetAllElementFromLocationTest, getSwitchTrackFromLocation) {
	Map *map = new Map();
	map->createAddSwitchTrack(SwitchType::SWITCH1,1,1);
	std::shared_ptr<SwitchTrack> track1 = map->getSwitchTrackAt(1,1);
	EXPECT_EQ(track1->getSwitchType(),SwitchType::SWITCH1);
	EXPECT_EQ(track1->getLocationX(),1);
	EXPECT_EQ(track1->getLocationY(),1);
	map->createAddSwitchTrack(SwitchType::SWITCHTIGHT1,-1,-1);
	std::shared_ptr<SwitchTrack> track2 = map->getSwitchTrackAt(-1,-1);
	EXPECT_EQ(track2->getSwitchType(),SwitchType::SWITCHTIGHT1);
	EXPECT_EQ(track2->getLocationX(),-1);
	EXPECT_EQ(track2->getLocationY(),-1);
	map->createAddSwitchTrack(SwitchType::SWITCHSPLIT1,2,2);
	std::shared_ptr<SwitchTrack> track3 = map->getSwitchTrackAt(2,2);
	EXPECT_EQ(track3->getSwitchType(),SwitchType::SWITCHSPLIT1);
	EXPECT_EQ(track3->getLocationX(),2);
	EXPECT_EQ(track3->getLocationY(),2);
}

TEST(MapGetAllElementFromLocationTest, getCrossoverTrackFromLocation) {
	Map *map = new Map();
	map->createAddCrossoverTrack(CrossoverType::CROSSOVER1,1,1);
	std::shared_ptr<CrossoverTrack> track1 = map->getCrossoverTrackAt(1,1);
	EXPECT_EQ(track1->getCrossoverType(),CrossoverType::CROSSOVER1);
	EXPECT_EQ(track1->getLocationX(),1);
	EXPECT_EQ(track1->getLocationY(),1);
	map->createAddCrossoverTrack(CrossoverType::CROSSOVER6,-1,-1);
	std::shared_ptr<CrossoverTrack> track2 = map->getCrossoverTrackAt(-1,-1);
	EXPECT_EQ(track2->getCrossoverType(),CrossoverType::CROSSOVER6);
	EXPECT_EQ(track2->getLocationX(),-1);
	EXPECT_EQ(track2->getLocationY(),-1);
}

TEST(MapGetAllElementFromLocationTest, getFlyoverTrackFromLocation) {
	Map *map = new Map();
	map->createAddFlyoverTrack(FlyoverType::FLYOVER1,1,1);
	std::shared_ptr<FlyoverTrack> track1 = map->getFlyoverTrackAt(1,1);
	EXPECT_EQ(track1->getFlyoverType(),FlyoverType::FLYOVER1);
	EXPECT_EQ(track1->getLocationX(),1);
	EXPECT_EQ(track1->getLocationY(),1);
	map->createAddFlyoverTrack(FlyoverType::FLYOVER8,-1,-1);
	std::shared_ptr<FlyoverTrack> track2 = map->getFlyoverTrackAt(-1,-1);
	EXPECT_EQ(track2->getFlyoverType(),FlyoverType::FLYOVER8);
	EXPECT_EQ(track2->getLocationX(),-1);
	EXPECT_EQ(track2->getLocationY(),-1);
}

TEST(MapGetAllElementFromLocationTest, getNamedLocationFromLocation) {
	Map *map = new Map();
	map->createAddNamedLocation(1,1);
	std::shared_ptr<NamedLocation> element1 = map->getNamedLocationAt(1,1);
	EXPECT_EQ(element1->getLocationX(),1);
	EXPECT_EQ(element1->getLocationY(),1);
	map->createAddNamedLocation(-1,-1);
	std::shared_ptr<NamedLocation> element2 = map->getNamedLocationAt(-1,-1);
	EXPECT_EQ(element2->getLocationX(),-1);
	EXPECT_EQ(element2->getLocationY(),-1);
}

TEST(MapGetAllElementFromLocationTest, getConcourseFromLocation) {
	Map *map = new Map();
	map->createAddConcourse(1,1);
	std::shared_ptr<Concourse> element1 = map->getConcourseAt(1,1);
	EXPECT_EQ(element1->getLocationX(),1);
	EXPECT_EQ(element1->getLocationY(),1);
	map->createAddConcourse(-1,-1);
	std::shared_ptr<Concourse> element2 = map->getConcourseAt(-1,-1);
	EXPECT_EQ(element2->getLocationX(),-1);
	EXPECT_EQ(element2->getLocationY(),-1);
}
