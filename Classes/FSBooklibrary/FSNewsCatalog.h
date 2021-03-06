//
//  FSNewsCatalog.h
//  SharpMessage
//
//  Created by apple on 6/7/15.
//
//

#ifndef __SharpMessage__FSNewsCatalog__
#define __SharpMessage__FSNewsCatalog__

#include <stdio.h>
#include "CrossApp.h"
#include "CrossAppExt.h"
#include "AppMacros.h"

class FSNewsCatalog:public CAViewController,public CATableViewDelegate ,public CATableViewDataSource
{
    
public:
    
    FSNewsCatalog();
    FSNewsCatalog(int newsId);
    
    virtual ~FSNewsCatalog();
    
protected:
    
    void viewDidLoad();
    
    void viewDidUnload();
    
//    void viewDidAppear();
    
public:
    void loadData();
private:
    
    void refreshView(bool isCatalog);
public:
    virtual void tableViewDidSelectRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row);
    virtual void tableViewDidDeselectRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row);
    
    virtual CATableViewCell* tableCellAtIndex(CATableView* table, const CCSize& cellSize, unsigned int section, unsigned int row);
//    virtual CAView* tableViewSectionViewForHeaderInSection(CATableView* table, const CCSize& viewSize, unsigned int section);
//    virtual CAView* tableViewSectionViewForFooterInSection(CATableView* table, const CCSize& viewSize, unsigned int section);
    virtual unsigned int numberOfRowsInSection(CATableView *table, unsigned int section);
    virtual unsigned int numberOfSections(CATableView *table);
    virtual unsigned int tableViewHeightForRowAtIndexPath(CATableView* table, unsigned int section, unsigned int row);
//    virtual unsigned int tableViewHeightForHeaderInSection(CATableView* table, unsigned int section);
//    virtual unsigned int tableViewHeightForFooterInSection(CATableView* table, unsigned int section);
    
public:
    void segmentCallback(CASegmentedControl* btn, int index);
    void alertClickBookMarkCleanCallBack(int btnIndex);
    
private:
    CADipSize size;
//    CATableView* p_TableViewMarklist;
    CASegmentedControl* segment;
    CATableView* p_TableView;
    int m_NewsId;
    CCArray *p_AryCatalog;
    CCArray *p_AryMarkInfo;
    
    static FSNewsCatalog* curFSNewsCatalog;
private:
    void showMarklist(bool isShow);
    
    CABarButtonItem* rightButton;
    
public:
    CATableView* p_TableViewMarklist;
    FSCAObject loadChapter;
    FSFloat gotoChapterProgress;
public:
    void onClickBookMarkClean(CAControl* btn, CCPoint point);
};




#endif /* defined(__SharpMessage__FSNewsCatalog__) */
