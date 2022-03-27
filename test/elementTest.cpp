#include <gtest/gtest.h>
#include "element.h"



TEST(ElementToQStringTest, elementLocationToQStringOutput) {
	std::shared_ptr<Element> namedLocation1(new NamedLocation(1,2));
	std::shared_ptr<Element> namedLocation2(new NamedLocation(100,6));
	std::shared_ptr<Element> namedLocation3(new NamedLocation(542671,-232342));
	EXPECT_EQ(namedLocation1->locationToQString().toStdString(),"1,2");
	EXPECT_EQ(namedLocation2->locationToQString().toStdString(),"100,6");
	EXPECT_EQ(namedLocation3->locationToQString().toStdString(),"542671,-232342");
}


TEST(TextToQStringTest, TextToQStringOutput) {
	QFont serifFont("Times", 10, QFont::Bold);
	std::shared_ptr<Text> text1(new Text(1,2,"hi",serifFont));
	std::shared_ptr<Text> text2(new Text(100,6,"bo",serifFont));
	EXPECT_EQ(text1->toQString().toStdString(),"Text,1,2,hi,Times,10,-1,5,700,0,0,0,0,0,0,0,0,0,0,1");
	EXPECT_EQ(text2->toQString().toStdString(),"Text,100,6,bo,Times,10,-1,5,700,0,0,0,0,0,0,0,0,0,0,1");

}

TEST(NamedLocationToQStringTest, namedLocationToQStringOutput) {
	std::shared_ptr<NamedLocation> namedLocation1(new NamedLocation(1,2));
	std::shared_ptr<NamedLocation> namedLocation2(new NamedLocation(100,6));
	std::shared_ptr<NamedLocation> namedLocation3(new NamedLocation(542671,-232342));
	EXPECT_EQ(namedLocation1->toQString().toStdString(),"NamedLocation,1,2");
	EXPECT_EQ(namedLocation2->toQString().toStdString(),"NamedLocation,100,6");
	EXPECT_EQ(namedLocation3->toQString().toStdString(),"NamedLocation,542671,-232342");
	QFont serifFont("Times", 10, QFont::Bold);
	std::shared_ptr<Text> text1(new Text(100,6,"apple",serifFont));
	namedLocation1->setText(text1);
	EXPECT_EQ(namedLocation1->toQString().toStdString(),"NamedLocation,1,2,apple");


}

TEST(ConcourseToQStringTest, concourseToQStringOutput) {
	std::shared_ptr<Concourse> concourse1(new Concourse(84,264));
	std::shared_ptr<Concourse> concourse2(new Concourse(102310,6000000));
	std::shared_ptr<Concourse> concourse3(new Concourse(-23542671,-23232342));
	EXPECT_EQ(concourse1->toQString().toStdString(),"Concourse,84,264");
	EXPECT_EQ(concourse2->toQString().toStdString(),"Concourse,102310,6000000");
	EXPECT_EQ(concourse3->toQString().toStdString(),"Concourse,-23542671,-23232342");

}

TEST(ParapetToQStringTest, parapetToQStringOutput) {
	std::shared_ptr<Parapet> parapet1(new Parapet(ParapetType::PARAPET1,1,2));
	std::shared_ptr<Parapet> parapet2(new Parapet(ParapetType::PARAPET12,100,6));
	std::shared_ptr<Parapet> parapet3(new Parapet(ParapetType::PARAPET5,542671,-232342));
    EXPECT_EQ(parapet1->toQString().toStdString(),"Parapet,P1,1,2");
    EXPECT_EQ(parapet2->toQString().toStdString(),"Parapet,P12,100,6");
    EXPECT_EQ(parapet3->toQString().toStdString(),"Parapet,P5,542671,-232342");

}
