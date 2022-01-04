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
	std::shared_ptr<Filesaver> filesaver = std::make_shared<Filesaver>();
	filesaver->setNewFilePath("./test_result.rly2");
	filesaver->saveRailway(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"Text");
	line = in.readLine();
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
	std::shared_ptr<Filesaver> filesaver = std::make_shared<Filesaver>();
	filesaver->setNewFilePath("./test_result.rly2");
	filesaver->saveRailway(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"Text");
	line = in.readLine();
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
	std::shared_ptr<Filesaver> filesaver = std::make_shared<Filesaver>();
	filesaver->setNewFilePath("./test_result.rly2");
	filesaver->saveRailway(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"Text");
	line = in.readLine();
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
	std::shared_ptr<Filesaver> filesaver = std::make_shared<Filesaver>();
	filesaver->setNewFilePath("./test_result.rly2");
	filesaver->saveRailway(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"Text");
	line = in.readLine();
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
	std::shared_ptr<Filesaver> filesaver = std::make_shared<Filesaver>();
	filesaver->setNewFilePath("./test_result.rly2");
	filesaver->saveRailway(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"Text");
	line = in.readLine();
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
	std::shared_ptr<Filesaver> filesaver = std::make_shared<Filesaver>();
	filesaver->setNewFilePath("./test_result.rly2");
	filesaver->saveRailway(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"Text");
	line = in.readLine();
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

TEST(FilesaverSaveFileTest, writeParapetText) {
	Map *map = new Map();
	QFont serifFont("Times", 10, QFont::Bold);
	map->createAddParapet(ParapetType::PARAPET1,1,1);
	map->createAddParapet(ParapetType::PARAPET28,2,2);
	map->createAddText(3,3,"Text1",serifFont);
	map->createAddText(4,4,"Text2",serifFont);
	std::shared_ptr<Filesaver> filesaver = std::make_shared<Filesaver>();
	filesaver->setNewFilePath("./test_result.rly2");
	filesaver->saveRailway(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"Text");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"3,3,Text1,Times,10,-1,5,700,0,0,0,0,0,0,0,0,0,0,1");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"4,4,Text2,Times,10,-1,5,700,0,0,0,0,0,0,0,0,0,0,1");
	line = in.readLine();
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
	EXPECT_EQ(line.toStdString(),"Concourse");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"Parapet");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"P1,1,1");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"P28,2,2");
	line = in.readLine();

}

TEST(FilesaverSaveFileTest, writeEverything) {
	Map *map = new Map();
	QFont serifFont("Times", 10, QFont::Bold);
	map->createAddText(1,1,"Text1",serifFont);
	map->createAddText(2,2,"Text2",serifFont);
	map->createAddStraightTrack(StraightType::STRAIGHTH,3,3);
	map->createAddStraightTrack(StraightType::STRAIGHTH,4,4);
	map->createAddDirectedTrack(DirectedType::DIRECTEDLEFT,5,5);
	map->createAddDirectedTrack(DirectedType::DIRECTEDLEFT,6,6);
	map->createAddCurvedTrack(CurvedType::CURVE1,7,7);
	map->createAddCurvedTrack(CurvedType::TIGHTCURVE1,8,8);
	map->createAddLinkedTrack(LinkedType::LINKRIGHT,9,9);
	map->createAddLinkedTrack(LinkedType::LINKLEFTDOWN,10,10);
	map->createAddExitTrack(ExitType::EXITLEFT,11,11);
	map->createAddExitTrack(ExitType::EXITRIGHTDOWN,12,12);
	map->createAddBufferTrack(BufferType::BUFFERLEFT,13,13);
	map->createAddBufferTrack(BufferType::BUFFERRIGHTDOWN,14,14);
	map->createAddSignalTrack(SignalType::SIGNALLEFT,4,15,15);
	map->createAddSignalTrack(SignalType::SIGNALRIGHTDOWN,4,16,16);
	map->createAddBridgeUnderpassTrack(BridgeUnderpassType::BRIDGE1,17,17);
	map->createAddBridgeUnderpassTrack(BridgeUnderpassType::UNDERPASS1,18,18);
	map->createAddSwitchTrack(SwitchType::SWITCH1,19,19);
	map->createAddSwitchTrack(SwitchType::SWITCHSPLIT1,20,20);
	map->createAddSwitchTrack(SwitchType::SWITCHTIGHT1,21,21);
	map->createAddCrossoverTrack(CrossoverType::CROSSOVER1,22,22);
	map->createAddCrossoverTrack(CrossoverType::CROSSOVER2,23,23);
	map->createAddFlyoverTrack(FlyoverType::FLYOVER1,24,24);
	map->createAddFlyoverTrack(FlyoverType::FLYOVER12,25,25);
	map->createAddNamedLocation(26,26);
	map->createAddNamedLocation(27,27);
	map->createAddConcourse(28,28);
	map->createAddConcourse(29,29);
	map->createAddParapet(ParapetType::PARAPET1,30,30);
	map->createAddParapet(ParapetType::PARAPET28,31,31);

	std::shared_ptr<Filesaver> filesaver = std::make_shared<Filesaver>();
	filesaver->setNewFilePath("./test_result.rly2");
	filesaver->saveRailway(map);
	QFile file("./test_result.rly2");
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line = in.readLine();
	EXPECT_EQ(line.toStdString(),"Text");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"1,1,Text1,Times,10,-1,5,700,0,0,0,0,0,0,0,0,0,0,1");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"2,2,Text2,Times,10,-1,5,700,0,0,0,0,0,0,0,0,0,0,1");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"StraightTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SH,3,3,200,100,0,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SH,4,4,200,100,0,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"DirectedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"DL,5,5,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"DL,6,6,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"CurvedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"C1,7,7,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"TC1,8,8,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"LinkedTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"LR,9,9,200,100,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"LLD,10,10,200,100,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"ExitTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"EL,11,11,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"ERD,12,12,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BufferTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BL,13,13,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BRD,14,14,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SignalTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SIGL,4,15,15,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SIGRD,4,16,16,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BridgeUnderpassTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"BR1,17,17,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"UP1,18,18,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SwitchTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SW1,19,19,200,100,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SWS1,20,20,200,100,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"SWT1,21,21,200,100,200,100,0,0");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"CrossoverTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"CR1,22,22,200,100,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"CR2,23,23,200,100,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"FlyoverTrack");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"F1,24,24,200,100,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"F12,25,25,200,100,200,100");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"NamedLocation");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"26,26");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"27,27");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"Concourse");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"28,28");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"29,29");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"Parapet");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"P1,30,30");
	line = in.readLine();
	EXPECT_EQ(line.toStdString(),"P28,31,31");

}
