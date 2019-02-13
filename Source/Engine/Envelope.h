//
//  Envelope.h
//
//  Created by Nigel Redmon on 12/18/12.
//  EarLevel Engineering: earlevel.com
//  Copyright 2012 Nigel Redmon
//
//  For a complete explanation of the adsr envelope generator and code,
//  read the series of articles by the author, starting here:
//  http://www.earlevel.com/main/2013/06/01/envelope-generators/
//
//  License:
//
//  This source code is provided as is, without warranty.
//  You may copy and distribute verbatim copies of this document.
//  You may modify and use this source code to create binary code for your own purposes, free or commercial.
//

#pragma once

class Envelope {
public:
    Envelope();

    ~Envelope();

    float process();

    float getOutput() const;

    int getState() const;

    void gate(int gate);

    void setAttackRate(float rate);

    void setDecayRate(float rate);

    void setReleaseRate(float rate);

    void setSustainLevel(float level);

    void setTargetRatioA(float targetRatio);

    void setTargetRatioDR(float targetRatio);

    void reset();

    enum envState {
        env_idle = 0,
        env_attack,
        env_decay,
        env_sustain,
        env_release
    };

protected:
    int state {env_idle};
    float output {0};
    float attackRate {0};
    float decayRate {0};
    float releaseRate {0};
    float attackCoef {0};
    float decayCoef {0};
    float releaseCoef {0};
    float sustainLevel {0};
    float targetRatioA {0};
    float targetRatioDR {0};
    float attackBase {0};
    float decayBase {0};
    float releaseBase {0};

    float calcCoef(float rate, float targetRatio) const;
};

inline float Envelope::process() {
    switch (state) {
        case env_idle:
            break;
        case env_attack:
            output = attackBase + output * attackCoef;
            if (output >= 1.0) {
                output = 1.0;
                state = env_decay;
            }
            break;
        case env_decay:
            output = decayBase + output * decayCoef;
            if (output <= sustainLevel) {
                output = sustainLevel;
                state = env_sustain;
            }
            break;
        case env_sustain:
            break;
        case env_release:
            output = releaseBase + output * releaseCoef;
            if (output <= 0.0) {
                output = 0.0;
                state = env_idle;
            }
        default:
            break;
    }
    return output;
}

inline void Envelope::gate(int gate) {
    if (gate)
        state = env_attack;
    else if (state != env_idle)
        state = env_release;
}

inline int Envelope::getState() const {
    return state;
}

inline void Envelope::reset() {
    state = env_idle;
    output = 0.0;
}

inline float Envelope::getOutput() const {
    return output;
}
