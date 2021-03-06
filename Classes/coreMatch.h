//
//  coreMatch.h
//  Match
//
//  Created by 程小二 on 14-2-13.
//
//

#ifndef Match_coreMatch_h
#define Match_coreMatch_h

#include "cocos2d.h"
#include "util.h"
#include "ShaderSprite.h"

USING_NS_CC;


class Prop;

class coreMatch : public Node
{
public:
    coreMatch();
    ~coreMatch();
    
    static coreMatch* create();
    bool init();
    
    void onTouch(Touch* touch);
    
    virtual void visit();
    
private:
    
    //update grey sprite, show tip match boxes, and compute progress timebar and engergy bar
    void update(float delta);
    
    void loadPlist();
    
    //set up all boxes position
    void setupBoxesPos();
    
    void createBoxes();
    
    void createItemBox(int r, int c, colorSpriteEnum ce);
    
    //read info from default value, construct new match boxes
    void constructBoxes(const colorSpriteEnum rc[ROW][COL]);
    
    //set one of box to be gray
    void setupGraySprite(int r, int c);
    
    //clear all grey boxes
    void clearGraySprites();
    
    //check if one touch is in one box
    void touchOneBox(cocos2d::Touch *touch);
    
    void boxSequenceDead(const std::vector<coord>& vecs, Vector<FiniteTimeAction*>& actions);    
    void moveBoxes();
    
    void moveOneBox(Vector<Sprite*>& runSprites, Vector<FiniteTimeAction*>& runActions, int c);
    
    void moveRowBoxes(int c);
        
    void fucknewBox(Vector<Sprite*>& runSprites, Vector<FiniteTimeAction*>& runActions, int r, int c);
    
    cocos2d::ActionInterval* moveAction(float duration, Point pt);
    
    void boxCollectionSeqeunceMove(Vector<FiniteTimeAction*>& shitVec,
                                   const Vector<Sprite*>& sprites,
                                   const Vector<FiniteTimeAction*>& actions);
    
    void clearMatchTips();
    
    void attackMonster(const std::vector<coord>& outPutVecs, Vector<FiniteTimeAction*>& actions);
    void startAttack(int r, int c);
    
    void randomShowMatchTip();
            
    const char* getspriteFrameFileName(colorSpriteEnum ce);
    
    void resetCanbeTouch();
        
    //enter game crazy status
    void enterCrazyStatus();
    
    //quit from game crazy status
    void quitCrazyStatus();
    
    void setupMotionBlur();
    
    void selectNextRenderTexture();
    
    void boxMove(Sprite* box, FiniteTimeAction* moveAction);
    
    //remove box
    void boxDie(int r, int c);
    
    CC_SYNTHESIZE(Point, _monster_Pos, monster_Pos)
    
    void excuteMatchFunc (std::vector<coord>& colleciton, colorSpriteEnum cs,
                          const char* particleFileName ="", int propR=0, int propC=0);
    
    void playPropAutoClear(int r, int c);
    void playPropBoomb(int r, int c);
    void playPropSameColorBoomb(int r ,int c);
    void playPropCrossBoomb(int r, int c);
    void playPropRandomBoomb(int r, int c);
    void playPropFiveColorBoomb(int r, int c);
    void playNormalBox(int r, int c);
    void flashLabelTTF(const char* name, int fontsize);
    
    void playParticleEffect(const char* particleFileName, int r, int c);
    void playBulletEffect(int r, int c);
    
    void playClearAccount();
    void playBoxesSmile();
    void transToMainScene();
    
    
private:
    SpriteBatchNode* _batchnode;
    
    ///show what the box is what kind of box
    colorSpriteEnum _rc[ROW][COL];
    
    //show box position
    cocos2d::Point _boxesPos[ROW][COL];
    
    //box house
    cocos2d::Sprite* _rcSprites[ROW][COL];
    
    //grey sprites
    cocos2d::Vector<Sprite*> _graysprites;
    
    //tip sprites
    cocos2d::Vector<Sprite*> _showTips;
    
    float _updateTime;
    float _updateGrayTime;
    float _updateTipTime;
    float _updateBarTime;
    float _updateCrazyTime;
    float _updatePropTime;
    
    bool  _canbTouch;
    bool  _bShowTip;
    
    float _continueAddTime;
    int   _continueTimes;
    
    //motion blur
    int _kRenderTextureCount;
    int _currentRenderTextureIndex;
    Vector<RenderTexture*> _renderTextures;
    
    //prop
    int _propcount;
    bool _bProduceProp;
    int _propSequence;
};

#endif

