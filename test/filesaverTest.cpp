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
	//QString line4 = in.readLine();
	//QString line5 = in.readLine();
	//QString line6 = in.readLine();



	//EXPECT_EQ(line3.toStdString(),"SV,100,6,200,100,0,0,0");
	//EXPECT_EQ(line4.toStdString(),"DirectedTrack");

	//EXPECT_EQ(line6.toStdString(),"DLU,100,6,200,100,0,0,0");

}
