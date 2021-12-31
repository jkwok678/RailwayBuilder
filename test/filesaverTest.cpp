#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include <QFile>
#include <QIODevice>
#include "map.h"
#include "element.h"
#include "track.h"
#include "filesaver.h"


TEST(FilesaverSaveFileTest, writeStraightTrackDirectedTrack) {
	Map *map = new Map();
	map->createAddStraightTrack(StraightType::STRAIGHTH,1,1);
	map->createAddDirectedTrack(DirectedType::DIRECTEDLEFT,2,2);
	map->createAddStraightTrack(StraightType::STRAIGHTH,3,3);
	map->createAddDirectedTrack(DirectedType::DIRECTEDLEFT,4,4);
	Filesaver *filesaver = new Filesaver("./test_result.rly2");
	filesaver->saveRailwayAs(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"StraightTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SH,1,1,200,100,0,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SH,3,3,200,100,0,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"DirectedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"DL,2,2,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"DL,4,4,200,100,0,0");
}

TEST(FilesaverSaveFileTest, writeCurvedTrackLinkedTrack) {
	Map *map = new Map();
	map->createAddCurvedTrack(CurvedType::CURVE1,1,1);
	map->createAddCurvedTrack(CurvedType::TIGHTCURVE1,2,2);
	map->createAddLinkedTrack(LinkedType::LINKRIGHT,3,3);
	map->createAddLinkedTrack(LinkedType::LINKLEFTDOWN,4,4);
	Filesaver *filesaver = new Filesaver("./test_result.rly2");
	filesaver->saveRailwayAs(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"StraightTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"DirectedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"CurvedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"C1,1,1,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"TC1,2,2,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"LinkedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"LR,3,3,200,100,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"LLD,4,4,200,100,0");
}

TEST(FilesaverSaveFileTest, writeExitTrackBufferTrack) {
	Map *map = new Map();
	map->createAddExitTrack(ExitType::EXITLEFT,1,1);
	map->createAddExitTrack(ExitType::EXITRIGHTDOWN,2,2);
	map->createAddBufferTrack(BufferType::BUFFERLEFT,3,3);
	map->createAddBufferTrack(BufferType::BUFFERRIGHTDOWN,4,4);
	Filesaver *filesaver = new Filesaver("./test_result.rly2");
	filesaver->saveRailwayAs(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"StraightTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"DirectedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"CurvedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"LinkedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"ExitTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"EL,1,1,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"ERD,2,2,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BufferTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BL,3,3,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BRD,4,4,200,100,0,0");
}

TEST(FilesaverSaveFileTest, writeSignalTrackBridgeUnderpassTrack) {
	Map *map = new Map();
	map->createAddSignalTrack(SignalType::SIGNALLEFT,4,1,1);
	map->createAddSignalTrack(SignalType::SIGNALRIGHTDOWN,4,2,2);
	map->createAddBridgeUnderpassTrack(BridgeUnderpassType::BRIDGE1,3,3);
	map->createAddBridgeUnderpassTrack(BridgeUnderpassType::UNDERPASS1,4,4);
	Filesaver *filesaver = new Filesaver("./test_result.rly2");
	filesaver->saveRailwayAs(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"StraightTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"DirectedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"CurvedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"LinkedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"ExitTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BufferTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SignalTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SIGL,4,1,1,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SIGRD,4,2,2,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BridgeUnderpassTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BR1,3,3,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"UP1,4,4,200,100,0,0");
}

TEST(FilesaverSaveFileTest, writeSwitchTrackCrossoverTrackFlyoverTrack) {
	Map *map = new Map();
	map->createAddSwitchTrack(SwitchType::SWITCH1,1,1);
	map->createAddSwitchTrack(SwitchType::SWITCHSPLIT1,2,2);
	map->createAddSwitchTrack(SwitchType::SWITCHTIGHT1,3,3);
	map->createAddCrossoverTrack(CrossoverType::CROSSOVER1,4,4);
	map->createAddCrossoverTrack(CrossoverType::CROSSOVER2,5,5);
	map->createAddFlyoverTrack(FlyoverType::FLYOVER1,6,6);
	map->createAddFlyoverTrack(FlyoverType::FLYOVER12,7,7);
	Filesaver *filesaver = new Filesaver("./test_result.rly2");
	filesaver->saveRailwayAs(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"StraightTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"DirectedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"CurvedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"LinkedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"ExitTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BufferTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SignalTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BridgeUnderpassTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SwitchTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SW1,1,1,200,100,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SWS1,2,2,200,100,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SWT1,3,3,200,100,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"CrossoverTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"CR1,4,4,200,100,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"CR2,5,5,200,100,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"FlyoverTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"F1,6,6,200,100,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"F12,7,7,200,100,200,100");
}

TEST(FilesaverSaveFileTest, writeNamedLocationConcourse) {
	Map *map = new Map();
	map->createAddNamedLocation(1,1);
	map->createAddNamedLocation(2,2);
	map->createAddConcourse(3,3);
	map->createAddConcourse(4,4);
	Filesaver *filesaver = new Filesaver("./test_result.rly2");
	filesaver->saveRailwayAs(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"StraightTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"DirectedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"CurvedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"LinkedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"ExitTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BufferTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SignalTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BridgeUnderpassTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SwitchTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"CrossoverTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"FlyoverTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"NamedLocation");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"1,1");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"2,2");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"Concourse");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"3,3");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"4,4");

}
