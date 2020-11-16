// xlloption.cpp - Sample xll project.
#include <cmath>
//Uncomment to build for versions of Excel prior to 2007
//#define XLOPERX XLOPER
#include "xll_option.h"
#include "../../keithalewis/fmsoption/fms_variate_normal.h"

using namespace fms;
using namespace xll;

AddIn xai_variate_normal(
	Function(XLL_HANDLE, "xll_variate_normal", "VARIATE.NORMAL")
	.Args({
		Arg(XLL_DOUBLE, "mu", "is the mean. Default is 0."),
		Arg(XLL_DOUBLE, "sigma", "is the standard deviation. Default is 1.")
	})
	.Category("Option")
	.FunctionHelp("Return handle to normal variate.")
	.Uncalced()
);
HANDLEX WINAPI xll_variate_normal(double mu, double sigma)
{
#pragma XLLEXPORT
	handle<variate_base<>> m(new variate_model(variate::normal(mu, sigma)));

	return m.get();
}

AddIn xai_option_value(
	Function(XLL_DOUBLE, "xll_option_value", "OPTION.VALUE")
	.Args({
		Arg(XLL_HANDLE, "m", "is a handle to a model."),
		Arg(XLL_DOUBLE, "f", "is the forward."),
		Arg(XLL_DOUBLE, "s", "is the volatility."),
		Arg(XLL_DOUBLE, "k", "is the strike."),
	})
	.FunctionHelp("Return the option value.")
	.Category("Option")
	//.HelpTopic("https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/tgamma-tgammaf-tgammal")
);
double WINAPI xll_option_value(HANDLEX m, double f, double s, double k)
{
#pragma XLLEXPORT
	return xll_option_value<variate::normal<>>(m, f, s, k);
}
#if 0
AddIn xai_option_delta(
	Function(XLL_DOUBLE, "xll_option_delta", "OPTION.DELTA")
	.Args({
		Arg(XLL_HANDLE, "m", "is a handle to a model."),
		Arg(XLL_DOUBLE, "f", "is the forward."),
		Arg(XLL_DOUBLE, "s", "is the volatility."),
		Arg(XLL_DOUBLE, "k", "is the strike."),
	})
	.FunctionHelp("Return the option delta.")
	.Category("Option")
	//.HelpTopic("https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/tgamma-tgammaf-tgammal")
);
double WINAPI xll_option_delta(HANDLEX m, double f, double s, double k)
{
#pragma XLLEXPORT
	return xll_option_delta<variate::normal<>>(m, f, s, k);
}

AddIn xai_option_gamma(
	Function(XLL_DOUBLE, "xll_option_gamma", "OPTION.GAMMA")
	.Args({
		Arg(XLL_HANDLE, "m", "is a handle to a model."),
		Arg(XLL_DOUBLE, "f", "is the forward."),
		Arg(XLL_DOUBLE, "s", "is the volatility."),
		Arg(XLL_DOUBLE, "k", "is the strike."),
	})
	.FunctionHelp("Return the option gamma.")
	.Category("Option")
	//.HelpTopic("https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/tgamma-tgammaf-tgammal")
);
double WINAPI xll_option_gamma(HANDLEX m, double f, double s, double k)
{
#pragma XLLEXPORT
	return xll_option_gamma<variate::normal<>>(m, f, s, k);
}

AddIn xai_option_vega(
	Function(XLL_DOUBLE, "xll_option_vega", "OPTION.VEGA")
	.Args({
		Arg(XLL_HANDLE, "m", "is a handle to a model."),
		Arg(XLL_DOUBLE, "f", "is the forward."),
		Arg(XLL_DOUBLE, "s", "is the volatility."),
		Arg(XLL_DOUBLE, "k", "is the strike."),
	})
	.FunctionHelp("Return the option vega.")
	.Category("Option")
	//.HelpTopic("https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/tgamma-tgammaf-tgammal")
);
double WINAPI xll_option_vega(HANDLEX m, double f, double s, double k)
{
#pragma XLLEXPORT
	return xll_option_vega<variate::normal<>>(m, f, s, k);
}

AddIn xai_option_implied(
	Function(XLL_DOUBLE, "xll_option_implied", "OPTION.IMPLIED")
	.Args({
		Arg(XLL_HANDLE, "m", "is a handle to a model."),
		Arg(XLL_DOUBLE, "f", "is the forward."),
		Arg(XLL_DOUBLE, "v", "is the option value."),
		Arg(XLL_DOUBLE, "k", "is the strike."),
		Arg(XLL_DOUBLE, "s0", "is the initial vol guess. Default is 0.1"),		
		Arg(XLL_WORD, "n", "is the maximum number of iterations. Default is 10."),
		Arg(XLL_DOUBLE, "eps", "is value precision. Default is sqrt of machine epsilon."),
	})
	.FunctionHelp("Return the option implied.")
	.Category("Option")
	//.HelpTopic("https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/tgamma-tgammaf-tgammal")
);
double WINAPI xll_option_implied(HANDLEX m, double f, double v, double k, double s0, WORD n, double eps)
{
#pragma XLLEXPORT
	return xll_option_implied<variate::normal<>>(m, f, v, k, s0, n, eps);
}
#endif