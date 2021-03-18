class Envelope
{
public:
	Envelope()
	{
		setSampleRate (44100.0);
		setParameters ({});
	}

	struct Parameters
	{
		float time  = 0.1f;
        float value = 1.0f;
        float target = 1.0f;
	};

	/** Sets the parameters that will be used by an ADSR object.

		You must have called setSampleRate() with the correct sample rate before
		this otherwise the values may be incorrect!

		@see getParameters
	*/
	void setParameters (const Parameters& newParameters)
	{
		currentParameters = newParameters;

		calculateRate (newParameters);

		if (currentState != State::idle)
			checkCurrentState();
	}

	const Parameters& getParameters() const    { return currentParameters; }

	bool isActive() const noexcept             { return currentState != State::idle; }

	void setSampleRate (double sampleRate)
	{
		jassert (sampleRate > 0.0);
        currentSampleRate = sampleRate;
	}

	void reset()
	{
		value = target;
		currentState = State::idle;
	}

	float getNextSample()
	{
		if (currentState == State::idle)
			return target;

		if (currentState == State::active)
		{
            if (target > value) {
                value += rate;
                if (value >= target) {
                    value = target;
                    currentState = State::idle;
                }
            } else {
                value -= rate;
                if (value <= target) {
                    value = target;
                    currentState = State::idle;
                }
            }
			
		}

		return value;
	}
    
    float getCurrentSample()
    {
        return value;
    }

private:
	void calculateRate (const Parameters& parameters)
	{
		// need to call setSampleRate() first!
		jassert (currentSampleRate > 0.0);

		rate  = (parameters.time  > 0.0f ? static_cast<float> (1.0f / (parameters.time * currentSampleRate))  : -1.0f);
	}

	void checkCurrentState()
	{
		if (currentState == State::active && rate <= 0.0f)  reset();
	}

	//==============================================================================
	enum class State { idle, active };

	State currentState = State::idle;
	Parameters currentParameters;

	double currentSampleRate = 0.0;
	float value = 0.0f, rate = 0.0f, target = 0.0f;
};

