#include "canvas.h"

Canvas::Canvas()
{
	setMinimumSize(640,480);
	QPalette pal = palette();
	// set white background
	pal.setColor(QPalette::Window, Qt::white);
	map = new Map();

	//Hints
	selectRed = new QImage(":/graphics/graphics/select1.png");
	selectGreen = new QImage(":/graphics/graphics/select2.png");
	selectBlue = new QImage(":/graphics/graphics/select3.png");
	setAutoFillBackground(true);
	loadAllTrackImages();
	setPalette(pal);
}

void Canvas::loadAllTrackImages()
{
	//ElementBlock1 images
	straightHImage = new QImage(":/graphics/graphics/straightH.png");
	straightVImage = new QImage(":/graphics/graphics/straightV.png");
	directLeftImage = new QImage(":/graphics/graphics/directLeft.png");
	directRightImage = new QImage(":/graphics/graphics/directRight.png");
	directUpImage = new QImage(":/graphics/graphics/directUp.png");
	directDownImage = new QImage(":/graphics/graphics/directDown.png");
	straightLeftUpImage = new QImage(":/graphics/graphics/straightLeftUp.png");
	straightRightUpImage = new QImage(":/graphics/graphics/straightRightUp.png");
	directLeftUpImage = new QImage(":/graphics/graphics/directLeftUp.png");
	directRightUpImage = new QImage(":/graphics/graphics/directRightUp.png");
	directRightDownImage = new QImage(":/graphics/graphics/directRightDown.png");
	directLeftDownImage = new QImage(":/graphics/graphics/directLeftDown.png");
	tightCurve1Image = new QImage(":/graphics/graphics/tightCurve1.png");
	tightCurve2Image = new QImage(":/graphics/graphics/tightCurve2.png");
	tightCurve3Image = new QImage(":/graphics/graphics/tightCurve3.png");
	tightCurve4Image = new QImage(":/graphics/graphics/tightCurve4.png");
	curve1Image = new QImage(":/graphics/graphics/curve1.png");
	curve2Image = new QImage(":/graphics/graphics/curve2.png");
	curve3Image = new QImage(":/graphics/graphics/curve3.png");
	curve4Image = new QImage(":/graphics/graphics/curve4.png");

	linkLeftUnsetImage = new QImage(":/graphics/graphics/linkLeftUnset.png");
	linkRightUnsetImage = new QImage(":/graphics/graphics/linkRightUnset.png");
	linkDownUnsetImage = new QImage(":/graphics/graphics/linkDownUnset.png");
	linkUpUnsetImage = new QImage(":/graphics/graphics/linkUpUnset.png");
	linkLeftUpUnsetImage = new QImage(":/graphics/graphics/linkLeftUpUnset.png");
	linkRightUpUnsetImage = new QImage(":/graphics/graphics/linkRightUpUnset.png");
	linkRightDownUnsetImage = new QImage(":/graphics/graphics/linkRightDownUnset.png");
	linkLeftDownUnsetImage = new QImage(":/graphics/graphics/linkLeftDownUnset.png");
	linkLeftSetImage = new QImage(":/graphics/graphics/linkLeftSet.png");
	linkRightSetImage = new QImage(":/graphics/graphics/linkRightSet.png");
	linkDownSetImage = new QImage(":/graphics/graphics/linkDownSet.png");
	linkUpSetImage = new QImage(":/graphics/graphics/linkUpSet.png");
	linkLeftUpSetImage = new QImage(":/graphics/graphics/linkLeftUpSet.png");
	linkRightUpSetImage = new QImage(":/graphics/graphics/linkRightUpSet.png");
	linkRightDownSetImage = new QImage(":/graphics/graphics/linkRightDownSet.png");
	linkLeftDownSetImage = new QImage(":/graphics/graphics/linkLeftDownSet.png");
	exitLeftImage = new QImage(":/graphics/graphics/exitLeft.png");
	exitRightImage = new QImage(":/graphics/graphics/exitRight.png");
	exitDownImage = new QImage(":/graphics/graphics/exitDown.png");
	exitUpImage = new QImage(":/graphics/graphics/exitUp.png");
	exitLeftUpImage = new QImage(":/graphics/graphics/exitLeftUp.png");
	exitRightUpImage = new QImage(":/graphics/graphics/exitRightUp.png");
	exitLeftDownImage = new QImage(":/graphics/graphics/exitLeftDown.png");
	exitRightDownImage = new QImage(":/graphics/graphics/exitRightDown.png");
	curve5Image = new QImage(":/graphics/graphics/curve5.png");
	curve6Image = new QImage(":/graphics/graphics/curve6.png");
	curve7Image = new QImage(":/graphics/graphics/curve7.png");
	curve8Image = new QImage(":/graphics/graphics/curve8.png");

	bufferLeftImage = new QImage(":/graphics/graphics/bufferLeft.png");
	bufferRightImage = new QImage(":/graphics/graphics/bufferRight.png");
	bufferDownImage = new QImage(":/graphics/graphics/bufferDown.png");
	bufferUpImage = new QImage(":/graphics/graphics/bufferUp.png");
	bufferLeftUpImage = new QImage(":/graphics/graphics/bufferLeftUp.png");
	bufferRightUpImage = new QImage(":/graphics/graphics/bufferRightUp.png");
	bufferLeftDownImage = new QImage(":/graphics/graphics/bufferLeftDown.png");
	bufferRightDownImage = new QImage(":/graphics/graphics/bufferRightDown.png");
	signalLeftImage = new QImage(":/graphics/graphics/signalLeft.png");
	signalRightImage = new QImage(":/graphics/graphics/signalRight.png");
	signalDownImage = new QImage(":/graphics/graphics/signalDown.png");
	signalUpImage = new QImage(":/graphics/graphics/signalUp.png");
	signalLeftUpImage = new QImage(":/graphics/graphics/signalLeftUp.png");
	signalRightUpImage = new QImage(":/graphics/graphics/signalRightUp.png");
	signalLeftDownImage = new QImage(":/graphics/graphics/signalLeftDown.png");
	signalRightDownImage = new QImage(":/graphics/graphics/signalRightDown.png");
	shuntLeftImage = new QImage(":/graphics/graphics/shuntLeftRed.png");
	shuntRightImage = new QImage(":/graphics/graphics/shuntRightRed.png");
	shuntDownImage = new QImage(":/graphics/graphics/shuntDownRed.png");
	shuntUpImage = new QImage(":/graphics/graphics/shuntUpRed.png");
	shuntLeftUpImage = new QImage(":/graphics/graphics/shuntLeftUpRed.png");
	shuntRightUpImage = new QImage(":/graphics/graphics/shuntRightUpRed.png");
	shuntLeftDownImage = new QImage(":/graphics/graphics/shuntLeftDownRed.png");
	shuntRightDownImage = new QImage(":/graphics/graphics/shuntRightDownRed.png");
	bridgeUnset1Image = new QImage(":/graphics/graphics/bridgeUnset1.png");
	bridgeUnset2Image = new QImage(":/graphics/graphics/bridgeUnset2.png");
	underpassUnset1Image = new QImage(":/graphics/graphics/underpassUnset1.png");
	underpassUnset2Image = new QImage(":/graphics/graphics/underpassUnset2.png");
	bridgeSet1Image = new QImage(":/graphics/graphics/brdigeSet1.png");
	bridgeSet2Image = new QImage(":/graphics/graphics/bridgeSet2.png");
	underpassSet1Image = new QImage(":/graphics/graphics/underpassSet1.png");
	underpassSet2Image = new QImage(":/graphics/graphics/underpassSet2.png");

	//ElementBlock2 images
	switchTight1Image = new QImage(":/graphics/graphics/switchTight1.png");
	switchTight2Image = new QImage(":/graphics/graphics/switchTight2.png");
	switchTight3Image = new QImage(":/graphics/graphics/switchTight3.png");
	switchTight4Image = new QImage(":/graphics/graphics/switchTight4.png");
	switchTight5Image = new QImage(":/graphics/graphics/switchTight5.png");
	switchTight6Image = new QImage(":/graphics/graphics/switchTight6.png");
	switchTight7Image = new QImage(":/graphics/graphics/switchTight7.png");
	switchTight8Image = new QImage(":/graphics/graphics/switchTight8.png");
	switchSplit1Image = new QImage(":/graphics/graphics/switchSplit1.png");
	switchSplit2Image = new QImage(":/graphics/graphics/switchSplit2.png");
	switchSplit3Image = new QImage(":/graphics/graphics/switchSplit3.png");

	switch1Image = new QImage(":/graphics/graphics/switch1.png");
	switch2Image = new QImage(":/graphics/graphics/switch2.png");
	switch3Image = new QImage(":/graphics/graphics/switch3.png");
	switch4Image = new QImage(":/graphics/graphics/switch4.png");
	switch5Image = new QImage(":/graphics/graphics/switch5.png");
	switch6Image = new QImage(":/graphics/graphics/switch6.png");
	switch7Image = new QImage(":/graphics/graphics/switch7.png");
	switch8Image = new QImage(":/graphics/graphics/switch8.png");
	switchSplit4Image = new QImage(":/graphics/graphics/switchSplit4.png");
	switchSplit5Image = new QImage(":/graphics/graphics/switchSplit5.png");
	switchSplit6Image = new QImage(":/graphics/graphics/switchSplit6.png");

	switch9Image = new QImage(":/graphics/graphics/switch9.png");
	switch10Image = new QImage(":/graphics/graphics/switch10.png");
	switch11Image = new QImage(":/graphics/graphics/switch11.png");
	switch12Image = new QImage(":/graphics/graphics/switch12.png");
	switch13Image = new QImage(":/graphics/graphics/switch13.png");
	switch14Image = new QImage(":/graphics/graphics/switch14.png");
	switch15Image = new QImage(":/graphics/graphics/switch15.png");
	switch16Image = new QImage(":/graphics/graphics/switch16.png");
	switchSplit7Image = new QImage(":/graphics/graphics/switchSplit7.png");
	switchSplit8Image = new QImage(":/graphics/graphics/switchSplit8.png");

	//ElementBlock3 images
	crossover1Image = new QImage(":/graphics/graphics/crossover1.png");
	crossover2Image = new QImage(":/graphics/graphics/crossover2.png");
	flyover1Image = new QImage(":/graphics/graphics/flyover1.png");
	flyover2Image = new QImage(":/graphics/graphics/flyover2.png");
	flyover3Image = new QImage(":/graphics/graphics/flyover3.png");
	flyover4Image = new QImage(":/graphics/graphics/flyover4.png");

	crossover3Image = new QImage(":/graphics/graphics/crossover3.png");
	crossover4Image = new QImage(":/graphics/graphics/crossover4.png");
	flyover5Image = new QImage(":/graphics/graphics/flyover5.png");
	flyover6Image = new QImage(":/graphics/graphics/flyover6.png");
	flyover7Image = new QImage(":/graphics/graphics/flyover7.png");
	flyover8Image = new QImage(":/graphics/graphics/flyover8.png");

	crossover5Image = new QImage(":/graphics/graphics/crossover5.png");
	crossover6Image = new QImage(":/graphics/graphics/crossover6.png");
	flyover9Image = new QImage(":/graphics/graphics/flyover9.png");
	flyover10Image = new QImage(":/graphics/graphics/flyover10.png");
	flyover11Image = new QImage(":/graphics/graphics/flyover11.png");
	flyover12Image = new QImage(":/graphics/graphics/flyover12.png");

	//ElementBlock4 images
	namedLocationUnsetImage = new QImage(":/graphics/graphics/namedLocationUnset.png");
	namedLocationSetImage = new QImage(":/graphics/graphics/namedLocationSet.png");
	concourseUnsetImage = new QImage(":/graphics/graphics/concourseUnset.png");
	concourseSetImage = new QImage(":/graphics/graphics/concourseSet.png");
	platformDownUnsetImage = new QImage(":/graphics/graphics/platformDownUnset.png");
	platformDownSetImage = new QImage(":/graphics/graphics/platformDownSet.png");
	platformUpUnsetImage = new QImage(":/graphics/graphics/platformUpUnset.png");
	platformUpSetImage = new QImage(":/graphics/graphics/platformUpSet.png");
	platformLeftUnsetImage = new QImage(":/graphics/graphics/platformLeftUnset.png");
	platformLeftSetImage = new QImage(":/graphics/graphics/platformLeftSet.png");
	platformRightUnsetImage = new QImage(":/graphics/graphics/platformRightUnset.png");
	platformRightSetImage = new QImage(":/graphics/graphics/platformRightSet.png");

	//ElementBlock5 images
	parapet1Image = new QImage(":/graphics/graphics/parapet1.png");
	parapet2Image = new QImage(":/graphics/graphics/parapet2.png");
	parapet3Image = new QImage(":/graphics/graphics/parapet3.png");
	parapet4Image = new QImage(":/graphics/graphics/parapet4.png");
	parapet5Image = new QImage(":/graphics/graphics/parapet5.png");
	parapet6Image = new QImage(":/graphics/graphics/parapet6.png");
	parapet7Image = new QImage(":/graphics/graphics/parapet7.png");
	parapet8Image = new QImage(":/graphics/graphics/parapet8.png");
	parapet9Image = new QImage(":/graphics/graphics/parapet9.png");
	parapet10Image = new QImage(":/graphics/graphics/parapet10.png");

	parapet11Image = new QImage(":/graphics/graphics/parapet11.png");
	parapet12Image = new QImage(":/graphics/graphics/parapet12.png");
	parapet13Image = new QImage(":/graphics/graphics/parapet13.png");
	parapet14Image = new QImage(":/graphics/graphics/parapet14.png");
	parapet15Image = new QImage(":/graphics/graphics/parapet15.png");
	parapet16Image = new QImage(":/graphics/graphics/parapet16.png");
	parapet17Image = new QImage(":/graphics/graphics/parapet17.png");
	parapet18Image = new QImage(":/graphics/graphics/parapet18.png");
	parapet19Image = new QImage(":/graphics/graphics/parapet19.png");
	parapet20Image = new QImage(":/graphics/graphics/parapet20.png");

	parapet21Image = new QImage(":/graphics/graphics/parapet21.png");
	parapet22Image = new QImage(":/graphics/graphics/parapet22.png");
	parapet23Image = new QImage(":/graphics/graphics/parapet23.png");
	parapet24Image = new QImage(":/graphics/graphics/parapet24.png");
	parapet25Image = new QImage(":/graphics/graphics/parapet25.png");
	parapet26Image = new QImage(":/graphics/graphics/parapet26.png");
	parapet27Image = new QImage(":/graphics/graphics/parapet27.png");
	parapet28Image = new QImage(":/graphics/graphics/parapet28.png");

	//ElementBlock6Image
	levelCrossingHImage = new QImage(":/graphics/graphics/levelCrossingH.png");
	levelCrossingVImage = new QImage(":/graphics/graphics/levelCrossingV.png");
}

void Canvas::loadAllRedTrackImages()
{
	//ElementBlock1 images
	straightHRedImage = new QImage(":/graphicsRed/graphicsRed/straightHRed.png");
	straightVRedImage = new QImage(":/graphicsRed/graphicsRed/straightVRed.png");
	directLeftRedImage = new QImage(":/graphicsRed/graphicsRed/directLeftRed.png");
	directRightRedImage = new QImage(":/graphicsRed/graphicsRed/directRightRed.png");
	directUpRedImage = new QImage(":/graphicsRed/graphicsRed/directUpRed.png");
	directDownRedImage = new QImage(":/graphicsRed/graphicsRed/directDownRed.png");
	straightLeftUpRedImage = new QImage(":/graphicsRed/graphicsRed/straightLeftUpRed.png");
	straightRightUpRedImage = new QImage(":/graphicsRed/graphicsRed/straightRightUpRed.png");
	directLeftUpRedImage = new QImage(":/graphicsRed/graphicsRed/directLeftUpRed.png");
	directRightUpRedImage = new QImage(":/graphicsRed/graphicsRed/directRightUpRed.png");
	directRightDownRedImage = new QImage(":/graphicsRed/graphicsRed/directRightDownRed.png");
	directLeftDownRedImage = new QImage(":/graphicsRed/graphicsRed/directLeftDownRed.png");
	tightCurve1RedImage = new QImage(":/graphicsRed/graphicsRed/tightCurve1Red.png");
	tightCurve2RedImage = new QImage(":/graphicsRed/graphicsRed/tightCurve2Red.png");
	tightCurve3RedImage = new QImage(":/graphicsRed/graphicsRed/tightCurve3Red.png");
	tightCurve4RedImage = new QImage(":/graphicsRed/graphicsRed/tightCurve4Red.png");
	curve1RedImage = new QImage(":/graphicsRed/graphicsRed/curve1Red.png");
	curve2RedImage = new QImage(":/graphicsRed/graphicsRed/curve2Red.png");
	curve3RedImage = new QImage(":/graphicsRed/graphicsRed/curve3Red.png");
	curve4RedImage = new QImage(":/graphicsRed/graphicsRed/curve4Red.png");

	linkLeftUnsetRedImage = new QImage(":/graphicsRed/graphicsRed/linkLeftUnsetRed.png");
	linkRightUnsetRedImage = new QImage(":/graphicsRed/graphicsRed/linkRightUnsetRed.png");
	linkDownUnsetRedImage = new QImage(":/graphicsRed/graphicsRed/linkDownUnsetRed.png");
	linkUpUnsetRedImage = new QImage(":/graphicsRed/graphicsRed/linkUpUnsetRed.png");
	linkLeftUpUnsetRedImage = new QImage(":/graphicsRed/graphicsRed/linkLeftUpUnsetRed.png");
	linkRightUpUnsetRedImage = new QImage(":/graphicsRed/graphicsRed/linkRightUpUnsetRed.png");
	linkRightDownUnsetRedImage = new QImage(":/graphicsRed/graphicsRed/linkRightDownUnsetRed.png");
	linkLeftDownUnsetRedImage = new QImage(":/graphicsRed/graphicsRed/linkLeftDownUnsetRed.png");
	linkLeftSetRedImage = new QImage(":/graphicsRed/graphicsRed/linkLeftSetRed.png");
	linkRightSetRedImage = new QImage(":/graphicsRed/graphicsRed/linkRightSetRed.png");
	linkDownSetRedImage = new QImage(":/graphicsRed/graphicsRed/linkDownSetRed.png");
	linkUpSetRedImage = new QImage(":/graphicsRed/graphicsRed/linkUpSetRed.png");
	linkLeftUpSetRedImage = new QImage(":/graphicsRed/graphicsRed/linkLeftUpSetRed.png");
	linkRightUpSetRedImage = new QImage(":/graphicsRed/graphicsRed/linkRightUpSetRed.png");
	linkRightDownSetRedImage = new QImage(":/graphicsRed/graphicsRed/linkRightDownSetRed.png");
	linkLeftDownSetRedImage = new QImage(":/graphicsRed/graphicsRed/linkLeftDownSetRed.png");
	exitLeftRedImage = new QImage(":/graphicsRed/graphicsRed/exitLeftRed.png");
	exitRightRedImage = new QImage(":/graphicsRed/graphicsRed/exitRightRed.png");
	exitDownRedImage = new QImage(":/graphicsRed/graphicsRed/exitDownRed.png");
	exitUpRedImage = new QImage(":/graphicsRed/graphicsRed/exitUpRed.png");
	exitLeftUpRedImage = new QImage(":/graphicsRed/graphicsRed/exitLeftUpRed.png");
	exitRightUpRedImage = new QImage(":/graphicsRed/graphicsRed/exitRightUpRed.png");
	exitLeftDownRedImage = new QImage(":/graphicsRed/graphicsRed/exitLeftDownRed.png");
	exitRightDownRedImage = new QImage(":/graphicsRed/graphicsRed/exitRightDownRed.png");
	curve5RedImage = new QImage(":/graphicsRed/graphicsRed/curve5Red.png");
	curve6RedImage = new QImage(":/graphicsRed/graphicsRed/curve6Red.png");
	curve7RedImage = new QImage(":/graphicsRed/graphicsRed/curve7Red.png");
	curve8RedImage = new QImage(":/graphicsRed/graphicsRed/curve8Red.png");

	bufferLeftRedImage = new QImage(":/graphicsRed/graphicsRed/bufferLeftRed.png");
	bufferRightRedImage = new QImage(":/graphicsRed/graphicsRed/bufferRightRed.png");
	bufferDownRedImage = new QImage(":/graphicsRed/graphicsRed/bufferDownRed.png");
	bufferUpRedImage = new QImage(":/graphicsRed/graphicsRed/bufferUpRed.png");
	bufferLeftUpRedImage = new QImage(":/graphicsRed/graphicsRed/bufferLeftUpRed.png");
	bufferRightUpRedImage = new QImage(":/graphicsRed/graphicsRed/bufferRightUpRed.png");
	bufferLeftDownRedImage = new QImage(":/graphicsRed/graphicsRed/bufferLeftDownRed.png");
	bufferRightDownRedImage = new QImage(":/graphicsRed/graphicsRed/bufferRightDownRed.png");
	signalLeftRedImage = new QImage(":/graphicsRed/graphicsRed/signalLeftRed.png");
	signalRightRedImage = new QImage(":/graphicsRed/graphicsRed/signalRightRed.png");
	signalDownRedImage = new QImage(":/graphicsRed/graphicsRed/signalDownRed.png");
	signalUpRedImage = new QImage(":/graphicsRed/graphicsRed/signalUpRed.png");
	signalLeftUpRedImage = new QImage(":/graphicsRed/graphicsRed/signalLeftUpRed.png");
	signalRightUpRedImage = new QImage(":/graphicsRed/graphicsRed/signalRightUpRed.png");
	signalLeftDownRedImage = new QImage(":/graphicsRed/graphicsRed/signalLeftDownRed.png");
	signalRightDownRedImage = new QImage(":/graphicsRed/graphicsRed/signalRightDownRed.png");
	shuntLeftRedImage = new QImage(":/graphicsRed/graphicsRed/shuntLeftRedRed.png");
	shuntRightRedImage = new QImage(":/graphicsRed/graphicsRed/shuntRightRedRed.png");
	shuntDownRedImage = new QImage(":/graphicsRed/graphicsRed/shuntDownRedRed.png");
	shuntUpRedImage = new QImage(":/graphicsRed/graphicsRed/shuntUpRedRed.png");
	shuntLeftUpRedImage = new QImage(":/graphicsRed/graphicsRed/shuntLeftUpRedRed.png");
	shuntRightUpRedImage = new QImage(":/graphicsRed/graphicsRed/shuntRightUpRedRed.png");
	shuntLeftDownRedImage = new QImage(":/graphicsRed/graphicsRed/shuntLeftDownRedRed.png");
	shuntRightDownRedImage = new QImage(":/graphicsRed/graphicsRed/shuntRightDownRedRed.png");
	bridgeUnset1RedImage = new QImage(":/graphicsRed/graphicsRed/bridgeUnset1Red.png");
	bridgeUnset2RedImage = new QImage(":/graphicsRed/graphicsRed/bridgeUnset2Red.png");
	underpassUnset1RedImage = new QImage(":/graphicsRed/graphicsRed/underpassUnset1Red.png");
	underpassUnset2RedImage = new QImage(":/graphicsRed/graphicsRed/underpassUnset2Red.png");
	bridgeSet1RedImage = new QImage(":/graphicsRed/graphicsRed/brdigeSet1Red.png");
	bridgeSet2RedImage = new QImage(":/graphicsRed/graphicsRed/bridgeSet2Red.png");
	underpassSet1RedImage = new QImage(":/graphicsRed/graphicsRed/underpassSet1Red.png");
	underpassSet2RedImage = new QImage(":/graphicsRed/graphicsRed/underpassSet2Red.png");

	//ElementBlock2 images
	switchTight1RedImage = new QImage(":/graphicsRed/graphicsRed/switchTight1Red.png");
	switchTight2RedImage = new QImage(":/graphicsRed/graphicsRed/switchTight2Red.png");
	switchTight3RedImage = new QImage(":/graphicsRed/graphicsRed/switchTight3Red.png");
	switchTight4RedImage = new QImage(":/graphicsRed/graphicsRed/switchTight4Red.png");
	switchTight5RedImage = new QImage(":/graphicsRed/graphicsRed/switchTight5Red.png");
	switchTight6RedImage = new QImage(":/graphicsRed/graphicsRed/switchTight6Red.png");
	switchTight7RedImage = new QImage(":/graphicsRed/graphicsRed/switchTight7Red.png");
	switchTight8RedImage = new QImage(":/graphicsRed/graphicsRed/switchTight8Red.png");
	switchSplit1RedImage = new QImage(":/graphicsRed/graphicsRed/switchSplit1Red.png");
	switchSplit2RedImage = new QImage(":/graphicsRed/graphicsRed/switchSplit2Red.png");
	switchSplit3RedImage = new QImage(":/graphicsRed/graphicsRed/switchSplit3Red.png");

	switch1RedImage = new QImage(":/graphicsRed/graphicsRed/switch1Red.png");
	switch2RedImage = new QImage(":/graphicsRed/graphicsRed/switch2Red.png");
	switch3RedImage = new QImage(":/graphicsRed/graphicsRed/switch3Red.png");
	switch4RedImage = new QImage(":/graphicsRed/graphicsRed/switch4Red.png");
	switch5RedImage = new QImage(":/graphicsRed/graphicsRed/switch5Red.png");
	switch6RedImage = new QImage(":/graphicsRed/graphicsRed/switch6Red.png");
	switch7RedImage = new QImage(":/graphicsRed/graphicsRed/switch7Red.png");
	switch8RedImage = new QImage(":/graphicsRed/graphicsRed/switch8Red.png");
	switchSplit4RedImage = new QImage(":/graphicsRed/graphicsRed/switchSplit4Red.png");
	switchSplit5RedImage = new QImage(":/graphicsRed/graphicsRed/switchSplit5Red.png");
	switchSplit6RedImage = new QImage(":/graphicsRed/graphicsRed/switchSplit6Red.png");

	switch9RedImage = new QImage(":/graphicsRed/graphicsRed/switch9Red.png");
	switch10RedImage = new QImage(":/graphicsRed/graphicsRed/switch10Red.png");
	switch11RedImage = new QImage(":/graphicsRed/graphicsRed/switch11Red.png");
	switch12RedImage = new QImage(":/graphicsRed/graphicsRed/switch12Red.png");
	switch13RedImage = new QImage(":/graphicsRed/graphicsRed/switch13Red.png");
	switch14RedImage = new QImage(":/graphicsRed/graphicsRed/switch14Red.png");
	switch15RedImage = new QImage(":/graphicsRed/graphicsRed/switch15Red.png");
	switch16RedImage = new QImage(":/graphicsRed/graphicsRed/switch16Red.png");
	switchSplit7RedImage = new QImage(":/graphicsRed/graphicsRed/switchSplit7Red.png");
	switchSplit8RedImage = new QImage(":/graphicsRed/graphicsRed/switchSplit8Red.png");

	//ElementBlock3 images
	crossover1RedImage = new QImage(":/graphicsRed/graphicsRed/crossover1Red.png");
	crossover2RedImage = new QImage(":/graphicsRed/graphicsRed/crossover2Red.png");
	flyover1RedImage = new QImage(":/graphicsRed/graphicsRed/flyover1Red.png");
	flyover2RedImage = new QImage(":/graphicsRed/graphicsRed/flyover2Red.png");
	flyover3RedImage = new QImage(":/graphicsRed/graphicsRed/flyover3Red.png");
	flyover4RedImage = new QImage(":/graphicsRed/graphicsRed/flyover4Red.png");

	crossover3RedImage = new QImage(":/graphicsRed/graphicsRed/crossover3Red.png");
	crossover4RedImage = new QImage(":/graphicsRed/graphicsRed/crossover4Red.png");
	flyover5RedImage = new QImage(":/graphicsRed/graphicsRed/flyover5Red.png");
	flyover6RedImage = new QImage(":/graphicsRed/graphicsRed/flyover6Red.png");
	flyover7RedImage = new QImage(":/graphicsRed/graphicsRed/flyover7Red.png");
	flyover8RedImage = new QImage(":/graphicsRed/graphicsRed/flyover8Red.png");

	crossover5RedImage = new QImage(":/graphicsRed/graphicsRed/crossover5Red.png");
	crossover6RedImage = new QImage(":/graphicsRed/graphicsRed/crossover6Red.png");
	flyover9RedImage = new QImage(":/graphicsRed/graphicsRed/flyover9Red.png");
	flyover10RedImage = new QImage(":/graphicsRed/graphicsRed/flyover10Red.png");
	flyover11RedImage = new QImage(":/graphicsRed/graphicsRed/flyover11Red.png");
	flyover12RedImage = new QImage(":/graphicsRed/graphicsRed/flyover12Red.png");
}

void Canvas::loadAllGreenTrackImages()
{
	//ElementBlock1 images
	straightHGreenImage = new QImage(":/graphicsGreen/graphicsGreen/straightHGreen.png");
	straightVGreenImage = new QImage(":/graphicsGreen/graphicsGreen/straightVGreen.png");
	directLeftGreenImage = new QImage(":/graphicsGreen/graphicsGreen/directLeftGreen.png");
	directRightGreenImage = new QImage(":/graphicsGreen/graphicsGreen/directRightGreen.png");
	directUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/directUpGreen.png");
	directDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/directDownGreen.png");
	straightLeftUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/straightLeftUpGreen.png");
	straightRightUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/straightRightUpGreen.png");
	directLeftUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/directLeftUpGreen.png");
	directRightUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/directRightUpGreen.png");
	directRightDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/directRightDownGreen.png");
	directLeftDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/directLeftDownGreen.png");
	tightCurve1GreenImage = new QImage(":/graphicsGreen/graphicsGreen/tightCurve1Green.png");
	tightCurve2GreenImage = new QImage(":/graphicsGreen/graphicsGreen/tightCurve2Green.png");
	tightCurve3GreenImage = new QImage(":/graphicsGreen/graphicsGreen/tightCurve3Green.png");
	tightCurve4GreenImage = new QImage(":/graphicsGreen/graphicsGreen/tightCurve4Green.png");
	curve1GreenImage = new QImage(":/graphicsGreen/graphicsGreen/curve1Green.png");
	curve2GreenImage = new QImage(":/graphicsGreen/graphicsGreen/curve2Green.png");
	curve3GreenImage = new QImage(":/graphicsGreen/graphicsGreen/curve3Green.png");
	curve4GreenImage = new QImage(":/graphicsGreen/graphicsGreen/curve4Green.png");

	linkLeftUnsetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkLeftUnsetGreen.png");
	linkRightUnsetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkRightUnsetGreen.png");
	linkDownUnsetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkDownUnsetGreen.png");
	linkUpUnsetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkUpUnsetGreen.png");
	linkLeftUpUnsetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkLeftUpUnsetGreen.png");
	linkRightUpUnsetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkRightUpUnsetGreen.png");
	linkRightDownUnsetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkRightDownUnsetGreen.png");
	linkLeftDownUnsetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkLeftDownUnsetGreen.png");
	linkLeftSetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkLeftSetGreen.png");
	linkRightSetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkRightSetGreen.png");
	linkDownSetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkDownSetGreen.png");
	linkUpSetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkUpSetGreen.png");
	linkLeftUpSetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkLeftUpSetGreen.png");
	linkRightUpSetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkRightUpSetGreen.png");
	linkRightDownSetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkRightDownSetGreen.png");
	linkLeftDownSetGreenImage = new QImage(":/graphicsGreen/graphicsGreen/linkLeftDownSetGreen.png");
	exitLeftGreenImage = new QImage(":/graphicsGreen/graphicsGreen/exitLeftGreen.png");
	exitRightGreenImage = new QImage(":/graphicsGreen/graphicsGreen/exitRightGreen.png");
	exitDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/exitDownGreen.png");
	exitUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/exitUpGreen.png");
	exitLeftUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/exitLeftUpGreen.png");
	exitRightUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/exitRightUpGreen.png");
	exitLeftDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/exitLeftDownGreen.png");
	exitRightDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/exitRightDownGreen.png");
	curve5GreenImage = new QImage(":/graphicsGreen/graphicsGreen/curve5Green.png");
	curve6GreenImage = new QImage(":/graphicsGreen/graphicsGreen/curve6Green.png");
	curve7GreenImage = new QImage(":/graphicsGreen/graphicsGreen/curve7Green.png");
	curve8GreenImage = new QImage(":/graphicsGreen/graphicsGreen/curve8Green.png");

	bufferLeftGreenImage = new QImage(":/graphicsGreen/graphicsGreen/bufferLeftGreen.png");
	bufferRightGreenImage = new QImage(":/graphicsGreen/graphicsGreen/bufferRightGreen.png");
	bufferDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/bufferDownGreen.png");
	bufferUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/bufferUpGreen.png");
	bufferLeftUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/bufferLeftUpGreen.png");
	bufferRightUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/bufferRightUpGreen.png");
	bufferLeftDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/bufferLeftDownGreen.png");
	bufferRightDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/bufferRightDownGreen.png");
	signalLeftGreenImage = new QImage(":/graphicsGreen/graphicsGreen/signalLeftGreen.png");
	signalRightGreenImage = new QImage(":/graphicsGreen/graphicsGreen/signalRightGreen.png");
	signalDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/signalDownGreen.png");
	signalUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/signalUpGreen.png");
	signalLeftUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/signalLeftUpGreen.png");
	signalRightUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/signalRightUpGreen.png");
	signalLeftDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/signalLeftDownGreen.png");
	signalRightDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/signalRightDownGreen.png");
	shuntLeftGreenImage = new QImage(":/graphicsGreen/graphicsGreen/shuntLeftRedGreen.png");
	shuntRightGreenImage = new QImage(":/graphicsGreen/graphicsGreen/shuntRightRedGreen.png");
	shuntDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/shuntDownRedGreen.png");
	shuntUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/shuntUpRedGreen.png");
	shuntLeftUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/shuntLeftUpRedGreen.png");
	shuntRightUpGreenImage = new QImage(":/graphicsGreen/graphicsGreen/shuntRightUpRedGreen.png");
	shuntLeftDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/shuntLeftDownRedGreen.png");
	shuntRightDownGreenImage = new QImage(":/graphicsGreen/graphicsGreen/shuntRightDownRedGreen.png");
	bridgeUnset1GreenImage = new QImage(":/graphicsGreen/graphicsGreen/bridgeUnset1Green.png");
	bridgeUnset2GreenImage = new QImage(":/graphicsGreen/graphicsGreen/bridgeUnset2Green.png");
	underpassUnset1GreenImage = new QImage(":/graphicsGreen/graphicsGreen/underpassUnset1Green.png");
	underpassUnset2GreenImage = new QImage(":/graphicsGreen/graphicsGreen/underpassUnset2Green.png");
	bridgeSet1GreenImage = new QImage(":/graphicsGreen/graphicsGreen/brdigeSet1Green.png");
	bridgeSet2GreenImage = new QImage(":/graphicsGreen/graphicsGreen/bridgeSet2Green.png");
	underpassSet1GreenImage = new QImage(":/graphicsGreen/graphicsGreen/underpassSet1Green.png");
	underpassSet2GreenImage = new QImage(":/graphicsGreen/graphicsGreen/underpassSet2Green.png");

	//ElementBlock2 images
	switchTight1GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchTight1Green.png");
	switchTight2GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchTight2Green.png");
	switchTight3GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchTight3Green.png");
	switchTight4GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchTight4Green.png");
	switchTight5GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchTight5Green.png");
	switchTight6GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchTight6Green.png");
	switchTight7GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchTight7Green.png");
	switchTight8GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchTight8Green.png");
	switchSplit1GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchSplit1Green.png");
	switchSplit2GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchSplit2Green.png");
	switchSplit3GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchSplit3Green.png");

	switch1GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch1Green.png");
	switch2GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch2Green.png");
	switch3GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch3Green.png");
	switch4GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch4Green.png");
	switch5GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch5Green.png");
	switch6GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch6Green.png");
	switch7GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch7Green.png");
	switch8GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch8Green.png");
	switchSplit4GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchSplit4Green.png");
	switchSplit5GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchSplit5Green.png");
	switchSplit6GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchSplit6Green.png");

	switch9GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch9Green.png");
	switch10GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch10Green.png");
	switch11GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch11Green.png");
	switch12GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch12Green.png");
	switch13GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch13Green.png");
	switch14GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch14Green.png");
	switch15GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch15Green.png");
	switch16GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switch16Green.png");
	switchSplit7GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchSplit7Green.png");
	switchSplit8GreenImage = new QImage(":/graphicsGreen/graphicsGreen/switchSplit8Green.png");

	//ElementBlock3 images
	crossover1GreenImage = new QImage(":/graphicsGreen/graphicsGreen/crossover1Green.png");
	crossover2GreenImage = new QImage(":/graphicsGreen/graphicsGreen/crossover2Green.png");
	flyover1GreenImage = new QImage(":/graphicsGreen/graphicsGreen/flyover1Green.png");
	flyover2GreenImage = new QImage(":/graphicsGreen/graphicsGreen/flyover2Green.png");
	flyover3GreenImage = new QImage(":/graphicsGreen/graphicsGreen/flyover3Green.png");
	flyover4GreenImage = new QImage(":/graphicsGreen/graphicsGreen/flyover4Green.png");

	crossover3GreenImage = new QImage(":/graphicsGreen/graphicsGreen/crossover3Green.png");
	crossover4GreenImage = new QImage(":/graphicsGreen/graphicsGreen/crossover4Green.png");
	flyover5GreenImage = new QImage(":/graphicsGreen/graphicsGreen/flyover5Green.png");
	flyover6GreenImage = new QImage(":/graphicsGreen/graphicsGreen/flyover6Green.png");
	flyover7GreenImage = new QImage(":/graphicsGreen/graphicsGreen/flyover7Green.png");
	flyover8GreenImage = new QImage(":/graphicsGreen/graphicsGreen/flyover8Green.png");

	crossover5GreenImage = new QImage(":/graphicsGreen/graphicsGreen/crossover5Green.png");
	crossover6GreenImage = new QImage(":/graphicsGreen/graphicsGreen/crossover6Green.png");
	flyover9GreenImage = new QImage(":/graphicsGreen/graphicsGreen/flyover9Green.png");
	flyover10GreenImage = new QImage(":/graphicsGreen/graphicsGreen/flyover10Green.png");
	flyover11GreenImage = new QImage(":/graphicsGreen/graphicsGreen/flyover11Green.png");
	flyover12GreenImage = new QImage(":/graphicsGreen/graphicsGreen/flyover12Green.png");

}

void Canvas::loadAllBlueTrackImages()
{
	//ElementBlock1 images
	straightHBlueImage = new QImage(":/graphicsBlue/graphicsBlue/straightHBlue.png");
	straightVBlueImage = new QImage(":/graphicsBlue/graphicsBlue/straightVBlue.png");
	directLeftBlueImage = new QImage(":/graphicsBlue/graphicsBlue/directLeftBlue.png");
	directRightBlueImage = new QImage(":/graphicsBlue/graphicsBlue/directRightBlue.png");
	directUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/directUpBlue.png");
	directDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/directDownBlue.png");
	straightLeftUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/straightLeftUpBlue.png");
	straightRightUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/straightRightUpBlue.png");
	directLeftUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/directLeftUpBlue.png");
	directRightUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/directRightUpBlue.png");
	directRightDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/directRightDownBlue.png");
	directLeftDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/directLeftDownBlue.png");
	tightCurve1BlueImage = new QImage(":/graphicsBlue/graphicsBlue/tightCurve1Blue.png");
	tightCurve2BlueImage = new QImage(":/graphicsBlue/graphicsBlue/tightCurve2Blue.png");
	tightCurve3BlueImage = new QImage(":/graphicsBlue/graphicsBlue/tightCurve3Blue.png");
	tightCurve4BlueImage = new QImage(":/graphicsBlue/graphicsBlue/tightCurve4Blue.png");
	curve1BlueImage = new QImage(":/graphicsBlue/graphicsBlue/curve1Blue.png");
	curve2BlueImage = new QImage(":/graphicsBlue/graphicsBlue/curve2Blue.png");
	curve3BlueImage = new QImage(":/graphicsBlue/graphicsBlue/curve3Blue.png");
	curve4BlueImage = new QImage(":/graphicsBlue/graphicsBlue/curve4Blue.png");

	linkLeftUnsetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkLeftUnsetBlue.png");
	linkRightUnsetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkRightUnsetBlue.png");
	linkDownUnsetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkDownUnsetBlue.png");
	linkUpUnsetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkUpUnsetBlue.png");
	linkLeftUpUnsetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkLeftUpUnsetBlue.png");
	linkRightUpUnsetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkRightUpUnsetBlue.png");
	linkRightDownUnsetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkRightDownUnsetBlue.png");
	linkLeftDownUnsetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkLeftDownUnsetBlue.png");
	linkLeftSetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkLeftSetBlue.png");
	linkRightSetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkRightSetBlue.png");
	linkDownSetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkDownSetBlue.png");
	linkUpSetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkUpSetBlue.png");
	linkLeftUpSetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkLeftUpSetBlue.png");
	linkRightUpSetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkRightUpSetBlue.png");
	linkRightDownSetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkRightDownSetBlue.png");
	linkLeftDownSetBlueImage = new QImage(":/graphicsBlue/graphicsBlue/linkLeftDownSetBlue.png");
	exitLeftBlueImage = new QImage(":/graphicsBlue/graphicsBlue/exitLeftBlue.png");
	exitRightBlueImage = new QImage(":/graphicsBlue/graphicsBlue/exitRightBlue.png");
	exitDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/exitDownBlue.png");
	exitUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/exitUpBlue.png");
	exitLeftUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/exitLeftUpBlue.png");
	exitRightUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/exitRightUpBlue.png");
	exitLeftDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/exitLeftDownBlue.png");
	exitRightDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/exitRightDownBlue.png");
	curve5BlueImage = new QImage(":/graphicsBlue/graphicsBlue/curve5Blue.png");
	curve6BlueImage = new QImage(":/graphicsBlue/graphicsBlue/curve6Blue.png");
	curve7BlueImage = new QImage(":/graphicsBlue/graphicsBlue/curve7Blue.png");
	curve8BlueImage = new QImage(":/graphicsBlue/graphicsBlue/curve8Blue.png");

	bufferLeftBlueImage = new QImage(":/graphicsBlue/graphicsBlue/bufferLeftBlue.png");
	bufferRightBlueImage = new QImage(":/graphicsBlue/graphicsBlue/bufferRightBlue.png");
	bufferDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/bufferDownBlue.png");
	bufferUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/bufferUpBlue.png");
	bufferLeftUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/bufferLeftUpBlue.png");
	bufferRightUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/bufferRightUpBlue.png");
	bufferLeftDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/bufferLeftDownBlue.png");
	bufferRightDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/bufferRightDownBlue.png");
	signalLeftBlueImage = new QImage(":/graphicsBlue/graphicsBlue/signalLeftBlue.png");
	signalRightBlueImage = new QImage(":/graphicsBlue/graphicsBlue/signalRightBlue.png");
	signalDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/signalDownBlue.png");
	signalUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/signalUpBlue.png");
	signalLeftUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/signalLeftUpBlue.png");
	signalRightUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/signalRightUpBlue.png");
	signalLeftDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/signalLeftDownBlue.png");
	signalRightDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/signalRightDownBlue.png");
	shuntLeftBlueImage = new QImage(":/graphicsBlue/graphicsBlue/shuntLeftRedBlue.png");
	shuntRightBlueImage = new QImage(":/graphicsBlue/graphicsBlue/shuntRightRedBlue.png");
	shuntDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/shuntDownRedBlue.png");
	shuntUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/shuntUpRedBlue.png");
	shuntLeftUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/shuntLeftUpRedBlue.png");
	shuntRightUpBlueImage = new QImage(":/graphicsBlue/graphicsBlue/shuntRightUpRedBlue.png");
	shuntLeftDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/shuntLeftDownRedBlue.png");
	shuntRightDownBlueImage = new QImage(":/graphicsBlue/graphicsBlue/shuntRightDownRedBlue.png");
	bridgeUnset1BlueImage = new QImage(":/graphicsBlue/graphicsBlue/bridgeUnset1Blue.png");
	bridgeUnset2BlueImage = new QImage(":/graphicsBlue/graphicsBlue/bridgeUnset2Blue.png");
	underpassUnset1BlueImage = new QImage(":/graphicsBlue/graphicsBlue/underpassUnset1Blue.png");
	underpassUnset2BlueImage = new QImage(":/graphicsBlue/graphicsBlue/underpassUnset2Blue.png");
	bridgeSet1BlueImage = new QImage(":/graphicsBlue/graphicsBlue/brdigeSet1Blue.png");
	bridgeSet2BlueImage = new QImage(":/graphicsBlue/graphicsBlue/bridgeSet2Blue.png");
	underpassSet1BlueImage = new QImage(":/graphicsBlue/graphicsBlue/underpassSet1Blue.png");
	underpassSet2BlueImage = new QImage(":/graphicsBlue/graphicsBlue/underpassSet2Blue.png");

	//ElementBlock2 images
	switchTight1BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchTight1Blue.png");
	switchTight2BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchTight2Blue.png");
	switchTight3BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchTight3Blue.png");
	switchTight4BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchTight4Blue.png");
	switchTight5BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchTight5Blue.png");
	switchTight6BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchTight6Blue.png");
	switchTight7BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchTight7Blue.png");
	switchTight8BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchTight8Blue.png");
	switchSplit1BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchSplit1Blue.png");
	switchSplit2BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchSplit2Blue.png");
	switchSplit3BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchSplit3Blue.png");

	switch1BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch1Blue.png");
	switch2BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch2Blue.png");
	switch3BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch3Blue.png");
	switch4BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch4Blue.png");
	switch5BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch5Blue.png");
	switch6BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch6Blue.png");
	switch7BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch7Blue.png");
	switch8BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch8Blue.png");
	switchSplit4BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchSplit4Blue.png");
	switchSplit5BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchSplit5Blue.png");
	switchSplit6BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchSplit6Blue.png");

	switch9BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch9Blue.png");
	switch10BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch10Blue.png");
	switch11BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch11Blue.png");
	switch12BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch12Blue.png");
	switch13BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch13Blue.png");
	switch14BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch14Blue.png");
	switch15BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch15Blue.png");
	switch16BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switch16Blue.png");
	switchSplit7BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchSplit7Blue.png");
	switchSplit8BlueImage = new QImage(":/graphicsBlue/graphicsBlue/switchSplit8Blue.png");

	//ElementBlock3 images
	crossover1BlueImage = new QImage(":/graphicsBlue/graphicsBlue/crossover1Blue.png");
	crossover2BlueImage = new QImage(":/graphicsBlue/graphicsBlue/crossover2Blue.png");
	flyover1BlueImage = new QImage(":/graphicsBlue/graphicsBlue/flyover1Blue.png");
	flyover2BlueImage = new QImage(":/graphicsBlue/graphicsBlue/flyover2Blue.png");
	flyover3BlueImage = new QImage(":/graphicsBlue/graphicsBlue/flyover3Blue.png");
	flyover4BlueImage = new QImage(":/graphicsBlue/graphicsBlue/flyover4Blue.png");

	crossover3BlueImage = new QImage(":/graphicsBlue/graphicsBlue/crossover3Blue.png");
	crossover4BlueImage = new QImage(":/graphicsBlue/graphicsBlue/crossover4Blue.png");
	flyover5BlueImage = new QImage(":/graphicsBlue/graphicsBlue/flyover5Blue.png");
	flyover6BlueImage = new QImage(":/graphicsBlue/graphicsBlue/flyover6Blue.png");
	flyover7BlueImage = new QImage(":/graphicsBlue/graphicsBlue/flyover7Blue.png");
	flyover8BlueImage = new QImage(":/graphicsBlue/graphicsBlue/flyover8Blue.png");

	crossover5BlueImage = new QImage(":/graphicsBlue/graphicsBlue/crossover5Blue.png");
	crossover6BlueImage = new QImage(":/graphicsBlue/graphicsBlue/crossover6Blue.png");
	flyover9BlueImage = new QImage(":/graphicsBlue/graphicsBlue/flyover9Blue.png");
	flyover10BlueImage = new QImage(":/graphicsBlue/graphicsBlue/flyover10Blue.png");
	flyover11BlueImage = new QImage(":/graphicsBlue/graphicsBlue/flyover11Blue.png");
	flyover12BlueImage = new QImage(":/graphicsBlue/graphicsBlue/flyover12Blue.png");
}


int Canvas::getOffsetX() const
{
	return offsetX;
}

void Canvas::setOffsetX(int newOffsetX)
{
	offsetX = newOffsetX;
}

int Canvas::getOffsetY() const
{
	return offsetY;
}

void Canvas::setOffsetY(int newOffsetY)
{
	offsetY = newOffsetY;
}

void Canvas::offsetMoveLeft()
{
	offsetX--;
}

void Canvas::offsetMoveRight()
{
	offsetX++;
}

void Canvas::offsetMoveUp()
{
	offsetY++;
}

void Canvas::offsetMoveDown()
{
	offsetY--;
}

Mode Canvas::getMode() const
{
	return mode;
}

void Canvas::setMode(Mode newMode)
{
	mode = newMode;
}

ElementChosen Canvas::getElementChosen() const
{
	return elementChosen;
}

void Canvas::setElementChosen(ElementChosen newElementChosen)
{
	elementChosen = newElementChosen;
}

int Canvas::getSignalAspectToAdd() const
{
	return signalAspectToAdd;
}

void Canvas::setSignalAspectToAdd(int newSignalAspectToAdd)
{
	signalAspectToAdd = newSignalAspectToAdd;
}

void Canvas::createAddElement(ElementChosen elementToAdd, int overallX, int overallY)
{
	bool addedTrack = false;
	switch (elementToAdd)
	{
		case ElementChosen::NONE:
		{
			QMessageBox noELementSelected;
			noELementSelected.setIcon(QMessageBox::Critical);
			noELementSelected.setText("No element has been selected.");
			noELementSelected.exec();
			break;
		}
		case ElementChosen::STRAIGHTH:
		{
			map->createAddStraightTrack(StraightType::STRAIGHTH, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::STRAIGHTV:
		{
			map->createAddStraightTrack(StraightType::STRAIGHTV, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::DIRECTEDLEFT:
		{
			map->createAddDirectedTrack(DirectedType::DIRECTEDLEFT, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::DIRECTEDRIGHT:
		{
			map->createAddDirectedTrack(DirectedType::DIRECTEDRIGHT, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::DIRECTEDUP:
		{
			map->createAddDirectedTrack(DirectedType::DIRECTEDUP, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::DIRECTEDDOWN:
		{
			map->createAddDirectedTrack(DirectedType::DIRECTEDDOWN, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::STRAIGHTRIGHTUP:
		{
			map->createAddStraightTrack(StraightType::STRAIGHTRIGHTUP, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::STRAIGHTLEFTUP:
		{
			map->createAddStraightTrack(StraightType::STRAIGHTLEFTUP, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::DIRECTEDRIGHTUP:
		{
			map->createAddDirectedTrack(DirectedType::DIRECTEDRIGHTUP, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::DIRECTEDLEFTUP:
		{
			map->createAddDirectedTrack(DirectedType::DIRECTEDLEFTUP, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::DIRECTEDLEFTDOWN:
		{
			map->createAddDirectedTrack(DirectedType::DIRECTEDLEFTDOWN, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::DIRECTEDRIGHTDOWN:
		{
			map->createAddDirectedTrack(DirectedType::DIRECTEDRIGHTDOWN, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::TIGHTCURVE1:
		{
			map->createAddCurvedTrack(CurvedType::TIGHTCURVE1, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::TIGHTCURVE2:
		{
			map->createAddCurvedTrack(CurvedType::TIGHTCURVE2, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::TIGHTCURVE3:
		{
			map->createAddCurvedTrack(CurvedType::TIGHTCURVE3, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::TIGHTCURVE4:
		{
			map->createAddCurvedTrack(CurvedType::TIGHTCURVE4, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CURVE1:
		{
			map->createAddCurvedTrack(CurvedType::CURVE1, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CURVE2:
		{
			map->createAddCurvedTrack(CurvedType::CURVE2, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CURVE3:
		{
			map->createAddCurvedTrack(CurvedType::CURVE3, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CURVE4:
		{
			map->createAddCurvedTrack(CurvedType::CURVE4, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::LINKLEFT:
		{
			map->createAddLinkedTrack(LinkedType::LINKLEFT, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::LINKRIGHT:
		{
			map->createAddLinkedTrack(LinkedType::LINKRIGHT, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::LINKDOWN:
		{
			map->createAddLinkedTrack(LinkedType::LINKDOWN, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::LINKUP:
		{
			map->createAddLinkedTrack(LinkedType::LINKUP, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::LINKLEFTUP:
		{
			map->createAddLinkedTrack(LinkedType::LINKLEFTUP, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::LINKRIGHTUP:
		{
			map->createAddLinkedTrack(LinkedType::LINKRIGHTUP, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::LINKRIGHTDOWN:
		{
			map->createAddLinkedTrack(LinkedType::LINKRIGHTDOWN, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::LINKLEFTDOWN:
		{
			map->createAddLinkedTrack(LinkedType::LINKLEFTDOWN, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::EXITLEFT:
		{
			map->createAddExitTrack(ExitType::EXITLEFT, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::EXITRIGHT:
		{
			map->createAddExitTrack(ExitType::EXITRIGHT, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::EXITDOWN:
		{
			map->createAddExitTrack(ExitType::EXITDOWN, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::EXITUP:
		{
			map->createAddExitTrack(ExitType::EXITUP, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::EXITLEFTUP:
		{
			map->createAddExitTrack(ExitType::EXITLEFTUP, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::EXITRIGHTUP:
		{
			map->createAddExitTrack(ExitType::EXITRIGHTUP, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::EXITLEFTDOWN:
		{
			map->createAddExitTrack(ExitType::EXITLEFTDOWN, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::EXITRIGHTDOWN:
		{
			map->createAddExitTrack(ExitType::EXITRIGHTDOWN, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CURVE5:
		{
			map->createAddCurvedTrack(CurvedType::CURVE5, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CURVE6:
		{
			map->createAddCurvedTrack(CurvedType::CURVE6, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CURVE7:
		{
			map->createAddCurvedTrack(CurvedType::CURVE7, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CURVE8:
		{
			map->createAddCurvedTrack(CurvedType::CURVE8, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::BUFFERLEFT:
		{
			map->createAddBufferTrack(BufferType::BUFFERLEFT, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::BUFFERRIGHT:
		{
			map->createAddBufferTrack(BufferType::BUFFERRIGHT, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::BUFFERDOWN:
		{
			map->createAddBufferTrack(BufferType::BUFFERDOWN, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::BUFFERUP:
		{
			map->createAddBufferTrack(BufferType::BUFFERUP, overallX, overallY);
			addedTrack = true;
			break;
		}

		case ElementChosen::BUFFERLEFTUP:
		{
			map->createAddBufferTrack(BufferType::BUFFERLEFTUP, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::BUFFERRIGHTUP:
		{
			map->createAddBufferTrack(BufferType::BUFFERRIGHTUP, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::BUFFERLEFTDOWN:
		{
			map->createAddBufferTrack(BufferType::BUFFERLEFTDOWN, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::BUFFERRIGHTDOWN:
		{
			map->createAddBufferTrack(BufferType::BUFFERRIGHTDOWN, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SIGNALLEFT:
		{
			map->createAddSignalTrack(SignalType::SIGNALLEFT,signalAspectToAdd, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SIGNALRIGHT:
		{
			map->createAddSignalTrack(SignalType::SIGNALRIGHT,signalAspectToAdd, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SIGNALDOWN:
		{
			map->createAddSignalTrack(SignalType::SIGNALDOWN,signalAspectToAdd, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SIGNALUP:
		{
			map->createAddSignalTrack(SignalType::SIGNALUP,signalAspectToAdd, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SIGNALLEFTUP:
		{
			map->createAddSignalTrack(SignalType::SIGNALLEFTUP,signalAspectToAdd, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SIGNALRIGHTUP:
		{
			map->createAddSignalTrack(SignalType::SIGNALRIGHTUP,signalAspectToAdd, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SIGNALLEFTDOWN:
		{
			map->createAddSignalTrack(SignalType::SIGNALLEFTDOWN,signalAspectToAdd, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SIGNALRIGHTDOWN:
		{
			map->createAddSignalTrack(SignalType::SIGNALRIGHTDOWN,signalAspectToAdd, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::BRIDGE1:
		{
			map->createAddBridgeUnderpassTrack(BridgeUnderpassType::BRIDGE1, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::BRIDGE2:
		{
			map->createAddBridgeUnderpassTrack(BridgeUnderpassType::BRIDGE2, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::UNDERPASS1:
		{
			map->createAddBridgeUnderpassTrack(BridgeUnderpassType::UNDERPASS1, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::UNDERPASS2:
		{
			map->createAddBridgeUnderpassTrack(BridgeUnderpassType::UNDERPASS2, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHTIGHT1:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHTIGHT1, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHTIGHT2:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHTIGHT2, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHTIGHT3:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHTIGHT3, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHTIGHT4:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHTIGHT4, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHTIGHT5:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHTIGHT5, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHTIGHT6:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHTIGHT6, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHTIGHT7:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHTIGHT7, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHTIGHT8:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHTIGHT8, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHSPLIT1:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHSPLIT1, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHSPLIT2:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHSPLIT2, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHSPLIT3:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHSPLIT3, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH1:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH1, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH2:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH2, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH3:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH3, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH4:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH4, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH5:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH5, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH6:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH6, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH7:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH7, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH8:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH8, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHSPLIT4:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHSPLIT4, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHSPLIT5:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHSPLIT5, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHSPLIT6:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHSPLIT6, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH9:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH9, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH10:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH10, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH11:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH11, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH12:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH12, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH13:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH13, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH14:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH14, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH15:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH15, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCH16:
		{
			map->createAddSwitchTrack(SwitchType::SWITCH16, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHSPLIT7:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHSPLIT7, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::SWITCHSPLIT8:
		{
			map->createAddSwitchTrack(SwitchType::SWITCHSPLIT8, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CROSSOVER1:
		{
			map->createAddCrossoverTrack(CrossoverType::CROSSOVER1, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CROSSOVER2:
		{
			map->createAddCrossoverTrack(CrossoverType::CROSSOVER2, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::FLYOVER1:
		{
			map->createAddFlyoverTrack(FlyoverType::FLYOVER1, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::FLYOVER2:
		{
			map->createAddFlyoverTrack(FlyoverType::FLYOVER2, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::FLYOVER3:
		{
			map->createAddFlyoverTrack(FlyoverType::FLYOVER3, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::FLYOVER4:
		{
			map->createAddFlyoverTrack(FlyoverType::FLYOVER4, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CROSSOVER3:
		{
			map->createAddCrossoverTrack(CrossoverType::CROSSOVER3, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CROSSOVER4:
		{
			map->createAddCrossoverTrack(CrossoverType::CROSSOVER4, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::FLYOVER5:
		{
			map->createAddFlyoverTrack(FlyoverType::FLYOVER5, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::FLYOVER6:
		{
			map->createAddFlyoverTrack(FlyoverType::FLYOVER6, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::FLYOVER7:
		{
			map->createAddFlyoverTrack(FlyoverType::FLYOVER7, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::FLYOVER8:
		{
			map->createAddFlyoverTrack(FlyoverType::FLYOVER8, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CROSSOVER5:
		{
			map->createAddCrossoverTrack(CrossoverType::CROSSOVER5, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::CROSSOVER6:
		{
			map->createAddCrossoverTrack(CrossoverType::CROSSOVER6, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::FLYOVER9:
		{
			map->createAddFlyoverTrack(FlyoverType::FLYOVER9, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::FLYOVER10:
		{
			map->createAddFlyoverTrack(FlyoverType::FLYOVER10, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::FLYOVER11:
		{
			map->createAddFlyoverTrack(FlyoverType::FLYOVER11, overallX, overallY);
			addedTrack = true;
			break;
		}
		case ElementChosen::FLYOVER12:
		{
			map->createAddFlyoverTrack(FlyoverType::FLYOVER12, overallX, overallY);
			addedTrack = true;
			break;
		}
	}
}


void Canvas::mousePressEvent(QMouseEvent *event)
{
	//Get size of the current Canvas Widget.
	canvasSizeX = width();
	canvasSizeY = height();
	//Getlocation of click.
	int exactX = event->pos().x();
	int exactY = event->pos().y();
	//Find out how close it is to the nearest image size. E.g. split the canvas into a grid with each square being imageSize big
	int extraX = exactX % imageSize;
	int extraY = exactY % imageSize;
	//Find the closest box to snap to.
	int roundedX = exactX - extraX;
	int roundedY = exactY - extraY;
	//Calculate overall coordinate
	int overallX = calculateOverallXCoordinate(roundedX);
	int overallY = calculateOverallYCoordinate(roundedY);

	bool addedTrack = false;
	if (event->button() == Qt::LeftButton)
	{
		createAddElement(elementChosen, overallX, overallY);
	}
	update();
}

void Canvas::paintEvent(QPaintEvent *event)
{
	canvasSizeX = width();
	canvasSizeY = height();

	if (mode == Mode::SETCONVERTSPEEDDISTANCE)
	{

	}
	else
	{
		//map->resetSetTrackSpeedLengthMechanics();
		QPainter painter(this);
		drawStraightTrack(painter);
		drawDirectedTrack(painter);
		drawCurvedTrack(painter);
		drawLinkedTrack(painter);
		drawExitTrack(painter);
		drawBufferTrack(painter);
		drawSignalTrack(painter);
		drawBridgeUnderpassTrack(painter);
		drawSwitchTrack(painter);
		drawCrossoverTrack(painter);
		drawFlyoverTrack(painter);
	}

}





int Canvas::calculateOverallXCoordinate(int roundedX)
{
	return roundedX + (offsetX*canvasSizeX);
}

int Canvas::calculateOverallYCoordinate(int roundedY)
{
	int finalY = 0;
	if (offsetY==0)
	{
		finalY = 0 - (roundedY+ (offsetY*canvasSizeY));
	}
	else
	{
		finalY = 0 - (roundedY- (offsetY*canvasSizeY));
	}
	return finalY;
}


void Canvas::drawStraightTrack(QPainter &painter)
{
	for (std::shared_ptr<StraightTrack> currentElement : map->getStraightTrackList())
	{
		//Get the stored location of track relative to the canvas widget.
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();

		//Find the area you want to output, by using the offset and the size of the canvas widget.
		int minCoordinateX = (offsetX * canvasSizeX);
		int maxCoordinateX = ((offsetX+1) * canvasSizeX);
		int minCoordinateY = ((offsetY-1) * canvasSizeY);
		int maxCoordinateY = (offsetY*canvasSizeY);;

		int minDisplayX = (offsetX * canvasSizeX);
		int maxDisplayX = ((offsetX+1) * canvasSizeX);
		int minDisplayY = ((offsetY-1) * canvasSizeY);
		int maxDisplayY = (offsetY*canvasSizeY);

		//Find the location on the canvas where you will draw
		if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
		{
			if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
			{
				int displayX = currentX- minDisplayX;
				int displayY = 0-(currentY - maxDisplayY);
				switch (currentElement->getStraightType())
				{
					case StraightType::STRAIGHTH:
					{
						//std::cout<< currentElement->getNamed() << std::flush;
						painter.drawImage(displayX, displayY, *straightHImage);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformUpSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformUpUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformDownSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformDownUnsetImage);
							}
						}
						if (currentElement->hasLevelCrossing())
						{
							painter.drawImage(displayX, displayY, *levelCrossingHImage);
						}
						break;
					}
					case StraightType::STRAIGHTV:
					{
						painter.drawImage(displayX, displayY, *straightVImage);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformLeftSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformRightSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformRightUnsetImage);
							}
						}
						if (currentElement->hasLevelCrossing())
						{
							painter.drawImage(displayX, displayY, *levelCrossingVImage);
						}
						break;
					}
					case StraightType::STRAIGHTRIGHTUP:
					{
						painter.drawImage(displayX, displayY, *straightRightUpImage);
						break;
					}
					case StraightType::STRAIGHTLEFTUP:
					{
						painter.drawImage(displayX, displayY, *straightLeftUpImage);
						break;
					}
				}
			}
		}
	}
}

void Canvas::drawDirectedTrack(QPainter &painter)
{
	for (std::shared_ptr<DirectedTrack> currentElement : map->getDirectedTrackList())
	{
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		int minCoordinateX = (offsetX * canvasSizeX);
		int maxCoordinateX = ((offsetX+1) * canvasSizeX);
		int minCoordinateY = ((offsetY-1) * canvasSizeY);
		int maxCoordinateY = (offsetY*canvasSizeY);;
		int minDisplayX = (offsetX * canvasSizeX);
		int maxDisplayY = (offsetY*canvasSizeY);
		if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
		{
			if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
			{
				int displayX = currentX- minDisplayX;
				int displayY = 0-(currentY - maxDisplayY);
				switch (currentElement->getDirectType())
				{
					case DirectedType::DIRECTEDLEFT:
					{
						painter.drawImage(displayX, displayY, *directLeftImage);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformUpSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformUpUnsetImage);
							}
						}
						if (currentElement->getPlatform2()) {
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformDownSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformDownUnsetImage);
							}
						}
						break;
					}
					case DirectedType::DIRECTEDRIGHT:
					{
						painter.drawImage(displayX, displayY, *directRightImage);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformUpSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformUpUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformDownSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformDownUnsetImage);
							}
						}
						break;
					}
					case DirectedType::DIRECTEDUP:
					{
						painter.drawImage(displayX, displayY, *directUpImage);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformLeftSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
							}
						}
						if (currentElement->getPlatform2()) {
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformRightSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformRightUnsetImage);
							}
						}
						break;
					}
					case DirectedType::DIRECTEDDOWN:
					{
						painter.drawImage(displayX, displayY, *directDownImage);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformLeftSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformRightSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformRightUnsetImage);
							}
						}
						break;
					}
					case DirectedType::DIRECTEDRIGHTUP:
					{
						painter.drawImage(displayX, displayY, *directRightUpImage);
						break;
					}
					case DirectedType::DIRECTEDLEFTUP:
					{
						painter.drawImage(displayX, displayY, *directLeftUpImage);
						break;
					}
					case DirectedType::DIRECTEDLEFTDOWN:
					{
						painter.drawImage(displayX, displayY, *directLeftDownImage);
						break;
					}
					case DirectedType::DIRECTEDRIGHTDOWN:
					{
						painter.drawImage(displayX, displayY, *directRightDownImage);
						break;
					}
				}
			}
		}
	}
}

void Canvas::drawCurvedTrack(QPainter &painter)
{
	for (std::shared_ptr<CurvedTrack> currentElement : map->getCurvedTrackList())
	{
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		int minCoordinateX = (offsetX * canvasSizeX);
		int maxCoordinateX = ((offsetX+1) * canvasSizeX);
		int minCoordinateY = ((offsetY-1) * canvasSizeY);
		int maxCoordinateY = (offsetY*canvasSizeY);;
		int minDisplayX = (offsetX * canvasSizeX);
		int maxDisplayY = (offsetY*canvasSizeY);
		if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
		{
			if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
			{
				int displayX = currentX- minDisplayX;
				int displayY = 0-(currentY - maxDisplayY);
				switch (currentElement->getCurvedType())
				{
					case CurvedType::TIGHTCURVE1:
					{
						painter.drawImage(displayX, displayY, *tightCurve1Image);
						break;
					}
					case CurvedType::TIGHTCURVE2:
					{
						painter.drawImage(displayX, displayY, *tightCurve2Image);
						break;
					}
					case CurvedType::TIGHTCURVE3:
					{
						painter.drawImage(displayX, displayY, *tightCurve3Image);
						break;
					}
					case CurvedType::TIGHTCURVE4:
						painter.drawImage(displayX, displayY, *tightCurve4Image);
						break;
					case CurvedType::CURVE1:
					{
						painter.drawImage(displayX, displayY, *curve1Image);
						break;
					}
					case CurvedType::CURVE2:
					{
						painter.drawImage(displayX, displayY, *curve2Image);
						break;
					}
					case CurvedType::CURVE3:
					{
						painter.drawImage(displayX, displayY, *curve3Image);
						break;
					}
					case CurvedType::CURVE4:
					{
						painter.drawImage(displayX, displayY, *curve4Image);
						break;
					}
					case CurvedType::CURVE5:
					{
						painter.drawImage(displayX, displayY, *curve5Image);
						break;
					}
					case CurvedType::CURVE6:
					{
						painter.drawImage(displayX, displayY, *curve6Image);
						break;
					}
					case CurvedType::CURVE7:
					{
						painter.drawImage(displayX, displayY, *curve7Image);
						break;
					}
					case CurvedType::CURVE8:
					{
						painter.drawImage(displayX, displayY, *curve8Image);
						break;
					}
				}
			}
		}
	}
}

void Canvas::drawLinkedTrack(QPainter &painter)
{
	for (std::shared_ptr<LinkedTrack> currentElement : map->getLinkedTrackList())
	{
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		int minCoordinateX = (offsetX * canvasSizeX);
		int maxCoordinateX = ((offsetX+1) * canvasSizeX);
		int minCoordinateY = ((offsetY-1) * canvasSizeY);
		int maxCoordinateY = (offsetY*canvasSizeY);;
		int minDisplayX = (offsetX * canvasSizeX);
		int maxDisplayY = (offsetY*canvasSizeY);
		if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
		{
			if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
			{
				int displayX = currentX- minDisplayX;
				int displayY = 0-(currentY - maxDisplayY);
				switch (currentElement->getLinkedType())
				{
					case LinkedType::LINKLEFT:
					{
						if (!currentElement->getLinked())
						{
							painter.drawImage(displayX, displayY, *linkLeftUnsetImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *linkLeftSetImage);
						}
						break;
					}
					case LinkedType::LINKRIGHT:
					{
						if (!currentElement->getLinked())
						{
							painter.drawImage(displayX, displayY, *linkRightUnsetImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *linkRightSetImage);
						}
						break;
					}
					case LinkedType::LINKDOWN:
					{
						if (!currentElement->getLinked())
						{
							painter.drawImage(displayX, displayY, *linkDownUnsetImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *linkDownSetImage);
						}
						break;
					}
					case LinkedType::LINKUP:
					{
						if (!currentElement->getLinked())
						{
							painter.drawImage(displayX, displayY, *linkUpUnsetImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *linkUpSetImage);
						}
						break;
					}
					case LinkedType::LINKLEFTUP:
					{
						if (!currentElement->getLinked())
						{
							painter.drawImage(displayX, displayY, *linkLeftUpUnsetImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *linkLeftUpSetImage);
						}
						break;
					}
					case LinkedType::LINKRIGHTUP:
					{
						if (!currentElement->getLinked())
						{
							painter.drawImage(displayX, displayY, *linkRightUpUnsetImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *linkRightUpSetImage);
						}
						break;
					}
					case LinkedType::LINKRIGHTDOWN:
					{
						if (!currentElement->getLinked())
						{
							painter.drawImage(displayX, displayY, *linkRightDownUnsetImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *linkRightDownSetImage);
						}
						break;
					}
					case LinkedType::LINKLEFTDOWN:
					{
						if (!currentElement->getLinked())
						{
							painter.drawImage(displayX, displayY, *linkLeftDownUnsetImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *linkLeftDownSetImage);
						}
						break;
					}
				}
			}
		}
	}

}

void Canvas::drawExitTrack(QPainter &painter)
{
	for (std::shared_ptr<ExitTrack> currentElement : map->getExitTrackList())
	{
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		int minCoordinateX = (offsetX * canvasSizeX);
		int maxCoordinateX = ((offsetX+1) * canvasSizeX);
		int minCoordinateY = ((offsetY-1) * canvasSizeY);
		int maxCoordinateY = (offsetY*canvasSizeY);;
		int minDisplayX = (offsetX * canvasSizeX);
		int maxDisplayY = (offsetY*canvasSizeY);
		if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
		{
			if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
			{
				int displayX = currentX- minDisplayX;
				int displayY = 0-(currentY - maxDisplayY);
				switch (currentElement->getExitType())
				{
					case ExitType::EXITLEFT:
					{
						painter.drawImage(displayX, displayY, *exitLeftImage);
						break;
					}
					case ExitType::EXITRIGHT:
					{
						painter.drawImage(displayX, displayY, *exitRightImage);
						break;
					}
					case ExitType::EXITDOWN:
					{
						painter.drawImage(displayX, displayY, *exitDownImage);
						break;
					}
					case ExitType::EXITUP:
					{
						painter.drawImage(displayX, displayY, *exitUpImage);
						break;
					}
					case ExitType::EXITLEFTUP:
					{
						painter.drawImage(displayX, displayY, *exitLeftUpImage);
						break;
					}
					case ExitType::EXITRIGHTUP:
					{
						painter.drawImage(displayX, displayY, *exitRightUpImage);
						break;
					}
					case ExitType::EXITLEFTDOWN:
					{
						painter.drawImage(displayX, displayY, *exitLeftDownImage);
						break;
					}
					case ExitType::EXITRIGHTDOWN:
					{
						painter.drawImage(displayX, displayY, *exitRightDownImage);
						break;
					}
				}
			}
		}
	}
}

void Canvas::drawBufferTrack(QPainter &painter)
{
	for (std::shared_ptr<BufferTrack> currentElement : map->getBufferTrackList())
	{
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		int minCoordinateX = (offsetX * canvasSizeX);
		int maxCoordinateX = ((offsetX+1) * canvasSizeX);
		int minCoordinateY = ((offsetY-1) * canvasSizeY);
		int maxCoordinateY = (offsetY*canvasSizeY);;
		int minDisplayX = (offsetX * canvasSizeX);
		int maxDisplayY = (offsetY*canvasSizeY);
		if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
		{
			if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
			{
				int displayX = currentX- minDisplayX;
				int displayY = 0-(currentY - maxDisplayY);
				switch (currentElement->getBufferType())
				{
					case BufferType::BUFFERLEFT:
					{
						painter.drawImage(displayX, displayY, *bufferLeftImage);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformUpSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformUpUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformDownSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformDownUnsetImage);
							}
						}
						break;
					}
					case BufferType::BUFFERRIGHT:
					{
						painter.drawImage(displayX, displayY, *bufferRightImage);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformUpSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformUpUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformDownSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformDownUnsetImage);
							}
						}
						break;
					}
					case BufferType::BUFFERDOWN:
					{
						painter.drawImage(displayX, displayY, *bufferDownImage);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformLeftSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformRightSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformRightUnsetImage);
							}
						}
						break;
					}
					case BufferType::BUFFERUP:
					{
						painter.drawImage(displayX, displayY, *bufferUpImage);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformLeftSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformRightSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformRightUnsetImage);
							}
						}
						break;
					}
					case BufferType::BUFFERLEFTUP:
					{
						painter.drawImage(displayX, displayY, *bufferLeftUpImage);
						break;
					}
					case BufferType::BUFFERRIGHTUP:
					{
						painter.drawImage(displayX, displayY, *bufferRightUpImage);
						break;
					}
					case BufferType::BUFFERLEFTDOWN:
					{
						painter.drawImage(displayX, displayY, *bufferLeftDownImage);
						break;
					}
					case BufferType::BUFFERRIGHTDOWN:
					{
						painter.drawImage(displayX, displayY, *bufferRightDownImage);
						break;
					}
				}
			}
		}
	}
}

void Canvas::drawSignalTrack(QPainter &painter)
{
	for (std::shared_ptr<SignalTrack> currentElement : map->getSignalTrackList())
	{
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		int minCoordinateX = (offsetX * canvasSizeX);
		int maxCoordinateX = ((offsetX+1) * canvasSizeX);
		int minCoordinateY = ((offsetY-1) * canvasSizeY);
		int maxCoordinateY = (offsetY*canvasSizeY);;
		int minDisplayX = (offsetX * canvasSizeX);
		int maxDisplayY = (offsetY*canvasSizeY);
		if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
		{
			if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
			{
				int displayX = currentX- minDisplayX;
				int displayY = 0-(currentY - maxDisplayY);
				switch (currentElement->getSignalType())
				{
					case SignalType::SIGNALLEFT:
					{
						if (currentElement->getAspect() == 1)
						{
							painter.drawImage(displayX, displayY, *shuntLeftImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *signalLeftImage);
						}
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformUpSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformUpUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformDownSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformDownUnsetImage);
							}
						}
						break;
					}
					case SignalType::SIGNALRIGHT:
					{
						if (currentElement->getAspect() == 1)
						{
							painter.drawImage(displayX, displayY, *shuntRightImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *signalRightImage);
						}
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformUpSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformUpUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformDownSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformDownUnsetImage);
							}
						}
						break;
					}
					case SignalType::SIGNALDOWN:
					{
						if (currentElement->getAspect() == 1)
						{
							painter.drawImage(displayX, displayY, *shuntDownImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *signalDownImage);
						}
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformLeftSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformRightSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformRightUnsetImage);
							}
						}
						break;
					}
					case SignalType::SIGNALUP:
					{
						if (currentElement->getAspect() == 1)
						{
							painter.drawImage(displayX, displayY, *shuntUpImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *signalUpImage);
						}
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformLeftSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformRightSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformRightUnsetImage);
							}
						}
						break;
					}
					case SignalType::SIGNALLEFTUP:
					{
						if (currentElement->getAspect() == 1)
						{
							painter.drawImage(displayX, displayY, *shuntLeftUpImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *signalLeftUpImage);
						}
						break;
					}
					case SignalType::SIGNALRIGHTUP:
					{
						if (currentElement->getAspect() == 1)
						{
							painter.drawImage(displayX, displayY, *shuntRightUpImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *signalRightUpImage);
						}
						break;
					}
					case SignalType::SIGNALLEFTDOWN:
					{
						if (currentElement->getAspect() == 1)
						{
							painter.drawImage(displayX, displayY, *shuntLeftDownImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *signalLeftDownImage);
						}
						break;
					}
					case SignalType::SIGNALRIGHTDOWN:
					{
						if (currentElement->getAspect() == 1)
						{
							painter.drawImage(displayX, displayY, *shuntRightDownImage);
						}
						else
						{
							painter.drawImage(displayX, displayY, *signalRightDownImage);
						}
						break;
					}
				}
			}
		}
	}
}

void Canvas::drawBridgeUnderpassTrack(QPainter &painter)
{
	for (std::shared_ptr<BridgeUnderpassTrack> currentElement : map->getBridgeUnderpassTrackList())
	{
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		int minCoordinateX = (offsetX * canvasSizeX);
		int maxCoordinateX = ((offsetX+1) * canvasSizeX);
		int minCoordinateY = ((offsetY-1) * canvasSizeY);
		int maxCoordinateY = (offsetY*canvasSizeY);;
		int minDisplayX = (offsetX * canvasSizeX);
		int maxDisplayY = (offsetY*canvasSizeY);
		if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
		{
			if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
			{
				int displayX = currentX- minDisplayX;
				int displayY = 0-(currentY - maxDisplayY);
				switch (currentElement->getBridgeUnderpassType())
				{
					case BridgeUnderpassType::BRIDGE1:
					{
						if (currentElement->getNamed())
						{
							painter.drawImage(displayX, displayY, *bridgeSet1Image);
						}
						else
						{
							painter.drawImage(displayX, displayY, *bridgeUnset1Image);
						}
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformUpSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformUpUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformDownSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformDownUnsetImage);
							}
						}
						break;
					}
					case BridgeUnderpassType::BRIDGE2:
					{
						if (currentElement->getNamed())
						{
							painter.drawImage(displayX, displayY, *bridgeSet2Image);
						}
						else
						{
							painter.drawImage(displayX, displayY, *bridgeUnset2Image);
						}
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformLeftSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformRightSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformRightUnsetImage);
							}
						}
						break;
					}
					case BridgeUnderpassType::UNDERPASS1:
					{
						if (currentElement->getNamed())
						{
							painter.drawImage(displayX, displayY, *underpassSet1Image);
						}
						else
						{
							painter.drawImage(displayX, displayY, *underpassUnset1Image);
						}
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformUpSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformUpUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformDownSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformDownUnsetImage);
							}
						}
						break;
					}
					case BridgeUnderpassType::UNDERPASS2:
					{
						if (currentElement->getNamed())
						{
							painter.drawImage(displayX, displayY, *underpassSet2Image);
						}
						else
						{
							painter.drawImage(displayX, displayY, *underpassUnset2Image);
						}
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformLeftSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
							}
						}
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformRightSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformRightUnsetImage);
							}
						}
						break;
					}
				}
			}
		}
	}
}

void Canvas::drawSwitchTrack(QPainter &painter)
{
	for (std::shared_ptr<SwitchTrack> currentElement : map->getSwitchTrackList())
	{
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		int minCoordinateX = (offsetX * canvasSizeX);
		int maxCoordinateX = ((offsetX+1) * canvasSizeX);
		int minCoordinateY = ((offsetY-1) * canvasSizeY);
		int maxCoordinateY = (offsetY*canvasSizeY);;
		int minDisplayX = (offsetX * canvasSizeX);
		int maxDisplayY = (offsetY*canvasSizeY);
		if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
		{
			if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
			{
				int displayX = currentX- minDisplayX;
				int displayY = 0-(currentY - maxDisplayY);
				switch (currentElement->getSwitchType())
				{
					case SwitchType::SWITCHTIGHT1:
					{
						painter.drawImage(displayX, displayY, *switchTight1Image);
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformDownSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformDownUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCHTIGHT2:
					{
						painter.drawImage(displayX, displayY, *switchTight2Image);
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformDownSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformDownUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCHTIGHT3:
					{
						painter.drawImage(displayX, displayY, *switchTight3Image);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformUpSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformUpUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCHTIGHT4:
					{
						painter.drawImage(displayX, displayY, *switchTight4Image);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformUpSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformUpUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCHTIGHT5:
					{
						painter.drawImage(displayX, displayY, *switchTight5Image);
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformRightSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformRightUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCHTIGHT6:
					{
						painter.drawImage(displayX, displayY, *switchTight6Image);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformLeftSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCHTIGHT7:
					{
						painter.drawImage(displayX, displayY, *switchTight7Image);
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformRightSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformRightUnsetImage);
							}
						}
					break;
					}
					case SwitchType::SWITCHTIGHT8:
					{
						painter.drawImage(displayX, displayY, *switchTight8Image);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformLeftSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCHSPLIT1:
					{
						painter.drawImage(displayX, displayY, *switchSplit1Image);
						break;
					}
					case SwitchType::SWITCHSPLIT2:
					{
						painter.drawImage(displayX, displayY, *switchSplit2Image);
						break;
					}
					case SwitchType::SWITCHSPLIT3:
					{
						painter.drawImage(displayX, displayY, *switchSplit3Image);
						break;
					}
					case SwitchType::SWITCH1:
					{
						painter.drawImage(displayX, displayY, *switch1Image);
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformDownSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformDownUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCH2:
					{
						painter.drawImage(displayX, displayY, *switch2Image);
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformDownSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformDownUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCH3:
					{
						painter.drawImage(displayX, displayY, *switch3Image);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformUpSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformUpUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCH4:
					{
						painter.drawImage(displayX, displayY, *switch4Image);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformUpSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformUpUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCH5:
					{
						painter.drawImage(displayX, displayY, *switch5Image);
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformRightSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformRightUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCH6:
					{
						painter.drawImage(displayX, displayY, *switch6Image);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformLeftSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCH7:
					{
						painter.drawImage(displayX, displayY, *switch7Image);
						if (currentElement->getPlatform2())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformRightSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformRightUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCH8:
					{
						painter.drawImage(displayX, displayY, *switch8Image);
						if (currentElement->getPlatform1())
						{
							if (currentElement->getNamed())
							{
								painter.drawImage(displayX, displayY, *platformLeftSetImage);
							}
							else
							{
								painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
							}
						}
						break;
					}
					case SwitchType::SWITCHSPLIT4:
					{
						painter.drawImage(displayX, displayY, *switchSplit4Image);
						break;
					}
					case SwitchType::SWITCHSPLIT5:
					{
						painter.drawImage(displayX, displayY, *switchSplit5Image);
						break;
					}
					case SwitchType::SWITCHSPLIT6:
					{
						painter.drawImage(displayX, displayY, *switchSplit6Image);
						break;
					}
					case SwitchType::SWITCH9:
					{
						painter.drawImage(displayX, displayY, *switch9Image);
						break;
					}
					case SwitchType::SWITCH10:
					{
						painter.drawImage(displayX, displayY, *switch10Image);
						break;
					}
					case SwitchType::SWITCH11:
					{
						painter.drawImage(displayX, displayY, *switch11Image);
						break;
					}
					case SwitchType::SWITCH12:
					{
						painter.drawImage(displayX, displayY, *switch12Image);
						break;
					}
					case SwitchType::SWITCH13:
					{
						painter.drawImage(displayX, displayY, *switch13Image);
						break;
					}
					case SwitchType::SWITCH14:
					{
						painter.drawImage(displayX, displayY, *switch14Image);
						break;
					}
					case SwitchType::SWITCH15:
					{
						painter.drawImage(displayX, displayY, *switch15Image);
						break;
					}
					case SwitchType::SWITCH16:
					{
						painter.drawImage(displayX, displayY, *switch16Image);
						break;
					}
					case SwitchType::SWITCHSPLIT7:
					{
						painter.drawImage(displayX, displayY, *switchSplit7Image);
						break;
					}
					case SwitchType::SWITCHSPLIT8:
					{
						painter.drawImage(displayX, displayY, *switchSplit8Image);
						break;
					}
				}
			}
		}
	}
}

void Canvas::drawCrossoverTrack(QPainter &painter)
{
	for (std::shared_ptr<CrossoverTrack> currentElement : map->getCrossoverTrackList())
	{
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		int minCoordinateX = (offsetX * canvasSizeX);
		int maxCoordinateX = ((offsetX+1) * canvasSizeX);
		int minCoordinateY = ((offsetY-1) * canvasSizeY);
		int maxCoordinateY = (offsetY*canvasSizeY);;
		int minDisplayX = (offsetX * canvasSizeX);
		int maxDisplayY = (offsetY*canvasSizeY);
		if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
		{
			if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
			{
				int displayX = currentX- minDisplayX;
				int displayY = 0-(currentY - maxDisplayY);
				switch (currentElement->getCrossoverType())
				{
					case CrossoverType::CROSSOVER1:
					{
						painter.drawImage(displayX, displayY, *crossover1Image);
						break;
					}
					case CrossoverType::CROSSOVER2:
					{
						painter.drawImage(displayX, displayY, *crossover2Image);
						break;
					}
					case CrossoverType::CROSSOVER3:
					{
						painter.drawImage(displayX, displayY, *crossover3Image);
						break;
					}
					case CrossoverType::CROSSOVER4:
					{
						painter.drawImage(displayX, displayY, *crossover4Image);
						break;
					}
					case CrossoverType::CROSSOVER5:
					{
						painter.drawImage(displayX, displayY, *crossover5Image);
						break;
					}
					case CrossoverType::CROSSOVER6:
					{
						painter.drawImage(displayX, displayY, *crossover6Image);
						break;
					}
				}
			}
		}
	}
}

void Canvas::drawFlyoverTrack(QPainter &painter)
{
	for (std::shared_ptr<FlyoverTrack> currentElement : map->getFlyoverTrackList())
	{
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		int minCoordinateX = (offsetX * canvasSizeX);
		int maxCoordinateX = ((offsetX+1) * canvasSizeX);
		int minCoordinateY = ((offsetY-1) * canvasSizeY);
		int maxCoordinateY = (offsetY*canvasSizeY);;
		int minDisplayX = (offsetX * canvasSizeX);
		int maxDisplayY = (offsetY*canvasSizeY);
		if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
		{
			if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
			{
				int displayX = currentX- minDisplayX;
				int displayY = 0-(currentY - maxDisplayY);
				switch (currentElement->getFlyoverType())
				{
					case FlyoverType::FLYOVER1:
					{
						painter.drawImage(displayX, displayY, *flyover1Image);
						break;
					}
					case FlyoverType::FLYOVER2:
					{
						painter.drawImage(displayX, displayY, *flyover2Image);
						break;
					}
					case FlyoverType::FLYOVER3:
					{
						painter.drawImage(displayX, displayY, *flyover3Image);
						break;
					}
					case FlyoverType::FLYOVER4:
					{
						painter.drawImage(displayX, displayY, *flyover4Image);
						break;
					}
					case FlyoverType::FLYOVER5:
					{
						painter.drawImage(displayX, displayY, *flyover5Image);
						break;
					}
					case FlyoverType::FLYOVER6:
					{
						painter.drawImage(displayX, displayY, *flyover6Image);
						break;
					}
					case FlyoverType::FLYOVER7:
					{
						painter.drawImage(displayX, displayY, *flyover7Image);
						break;
					}
					case FlyoverType::FLYOVER8:
					{
						painter.drawImage(displayX, displayY, *flyover8Image);
						break;
					}
					case FlyoverType::FLYOVER9:
					{
						painter.drawImage(displayX, displayY, *flyover9Image);
						break;
					}
					case FlyoverType::FLYOVER10:
					{
						painter.drawImage(displayX, displayY, *flyover10Image);
						break;
					}
					case FlyoverType::FLYOVER11:
					{
						painter.drawImage(displayX, displayY, *flyover11Image);
						break;
					}
					case FlyoverType::FLYOVER12:
					{
						painter.drawImage(displayX, displayY, *flyover12Image);
						break;
					}
				}
			}
		}
	}
}
