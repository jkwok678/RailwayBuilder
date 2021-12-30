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
