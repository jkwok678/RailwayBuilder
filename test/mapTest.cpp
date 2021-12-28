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
	EXPECT_EQ(map->linkedTrackListToQStringForSaving().toStdString(),"LR,1,2,200,100,0\nLU,100,6,200,100,0\n");
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
	map->createAddBufferTrack(BufferType::BUFFERUP,542671,-232342);
	EXPECT_EQ(map->bufferTrackListToQStringForSaving().toStdString(),"BL,1,2,200,100,0,0\nBRD,100,6,200,100,0,0\nBU,542671,-232342,200,100,0,0\n");
}

TEST(MapSavingQStringTest, signalTrackListToQString) {
	Map *map = new Map();
	map->createAddSignalTrack(SignalType::SIGNALLEFT,4,1,2);
	EXPECT_EQ(map->signalTrackListToQStringForSaving().toStdString(),"SIGL,4,1,2,200,100,0,0\n");
	map->createAddSignalTrack(SignalType::SIGNALRIGHTDOWN,4,100,6);
	EXPECT_EQ(map->signalTrackListToQStringForSaving().toStdString(),"SIGL,4,1,2,200,100,0,0\nSIGRD,4,100,6,200,100,0,0\n");
	map->createAddSignalTrack(SignalType::SIGNALUP,4,542671,-232342);
	EXPECT_EQ(map->signalTrackListToQStringForSaving().toStdString(),"SIGL,4,1,2,200,100,0,0\nSIGRD,4,100,6,200,100,0,0\nSIGU,4,542671,-232342,200,100,0,0\n");
}

TEST(MapSavingQStringTest, bridgeUnderpassTrackListToQString) {
	Map *map = new Map();
	map->createAddBridgeUnderpassTrack(BridgeUnderpassType::BRIDGE1,1,2);
	EXPECT_EQ(map->bridgeUnderpassTrackListToQStringForSaving().toStdString(),"BR1,1,2,200,100,200,100,0,0\n");
	map->createAddBridgeUnderpassTrack(BridgeUnderpassType::BRIDGE2,100,6);
	EXPECT_EQ(map->bridgeUnderpassTrackListToQStringForSaving().toStdString(),"BR1,1,2,200,100,200,100,0,0\nBR2,100,6,200,100,200,100,0,0\n");
	map->createAddBridgeUnderpassTrack(BridgeUnderpassType::UNDERPASS2,542671,-232342);
	EXPECT_EQ(map->bridgeUnderpassTrackListToQStringForSaving().toStdString(),"BR1,1,2,200,100,200,100,0,0\nBR2,100,6,200,100,200,100,0,0\nUP2,542671,-232342,200,100,200,100,0,0\n");
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
