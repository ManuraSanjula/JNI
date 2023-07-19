package test14;

@FunctionalInterface
public interface MathFunction {

	double value(double x) ; // only one abstract method --> use as lambda expression

	default double valueScaled(double x) {
		return value(x)*5.0 ;
	}

	static MathFunction functionScaled(MathFunction func) {
		return x -> func.value(x)*5.0 ;
	}

}
