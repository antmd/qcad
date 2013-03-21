function init(basePath) {
    var action = new RGuiAction(qsTranslate("Arc2PR", "&2 Points and Radius"), RMainWindowQt.getMainWindow());
    action.setRequiresDocument(true);
    action.setScriptFile(basePath + "/Arc2PR.js");
    action.setIcon(basePath + "/Arc2PR.svg");
    action.setStatusTip(qsTranslate("Arc2PR", "Draw arc from 2 points and radius"));
    action.setDefaultShortcut(new QKeySequence("a,d"));
    action.setDefaultCommands(["arcradius", "ad"]);
    action.setSortOrder(200);
    EAction.addGuiActionTo(action, Arc, true, true, true, true);
}