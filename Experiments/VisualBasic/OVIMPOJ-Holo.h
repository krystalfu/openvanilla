// OVIMPOJHolo-Holo.h: POJ-Holo input method

// Copyright (c) 2004-2005 by Lukhnos D. Liu, Kang-ming Liu, and Pek-tiong Tan

#ifndef __OVIMPOJHoloHolo_h
#define __OVIMPOJHoloHolo_h

#include "OpenVanilla.h"
#include "OVUtility.h"
#include "OVLibrary.h"
#include "OVCIN.h"
#include "OVCandidateList.h"
#include "POJ-Holo.h"

class OVIMPOJHolo;

class OVIMPOJHoloContext : public OVInputMethodContext {
public:
    OVIMPOJHoloContext(OVIMPOJHolo *p, OVCIN *ct);
    ~OVIMPOJHoloContext();
    
    virtual void clear();
    virtual int keyEvent(OVKeyCode *key, OVBuffer *buf, OVCandidate *textbar,
        OVService *srv);
    
protected:
    virtual int candidateEvent(OVKeyCode *key, OVBuffer *buf,
        OVCandidate*textbar, OVService *srv);
    virtual void queryAndCompose(const char *qstr, const char *disp, 
        OVBuffer *buf, OVCandidate *textbar, OVService *srv);

    OVIMPOJHolo *parent;
    POJHoloKeySequence seq;
    OVCandidateList candi;
    OVCIN *cintab;
    vector<string> list;
};


class OVIMPOJHolo : public OVInputMethod {
public:
    OVIMPOJHolo();
    virtual const char* identifier();
    virtual const char* localizedName(const char *cfge);
    virtual int initialize(OVDictionary*, OVService*, const char*);
    virtual void update(OVDictionary*, OVService*);  
    virtual OVInputMethodContext *newContext();

    virtual int isAsciiOutput() { return asciioutput; }
    virtual int getKeyLayout() { return keylayout; }
    virtual int isFullPOJ() { return fullPOJOutput; }
    
protected:
    int fullPOJOutput;
    int asciioutput;
    int keylayout;
    OVCIN *cintab;
};

#endif