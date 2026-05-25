#include "YMD.h"
#include <vector>
#include "Outputs.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms::DataVisualization::Charting;

void YMD_setup(Chart^ chart, YMD_Carrier& carrier)
{
    chart->Series->Clear();
    chart->ChartAreas->Clear();

    ChartArea^ area = gcnew ChartArea("Main");

    area->AxisX->Title = "Lateral Acceleration (g)";
    area->AxisY->Title = "Yaw Moment (Nm)";

    area->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray;
    area->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;

    area->AxisX->Minimum = -carrier.max_a_lat - 0.2;
    area->AxisX->Maximum = carrier.max_a_lat + 0.2;

	area->AxisY->Minimum = -carrier.max_M_yaw - 1000.0;
	area->AxisY->Maximum = carrier.max_M_yaw + 1000.0;

    area->AxisX->Interval = 0.2;
    area->AxisX->IntervalOffset = 0.0;

    area->AxisY->Interval = 1000.0;
    area->AxisY->IntervalOffset = 0.0;

    chart->ChartAreas->Add(area);
}

void YMD_clear(Chart^ chart)
{
    for each (Series ^ s in chart->Series)
        s->Points->Clear();
}

void YMD_plot(Chart^ chart, YMD_Carrier& carrier)
{
    int intensity = 0.0;
    Color base_beta = Color::Red;

    for (size_t j = 0; j < carrier.a_lat_isobeta.size(); j++) {

        intensity = j * 255 / carrier.a_lat_isobeta.size();

        std::vector<double>& x = carrier.a_lat_isobeta[j];
        std::vector<double>& y = carrier.M_yaw_isobeta[j];
        std::vector<double>& a_lon = carrier.a_lon_isobeta[j];
        std::vector<double>& R = carrier.R_isobeta[j];
        std::vector<double>& V = carrier.V_isobeta[j];
        std::vector<double>& r = carrier.r_isobeta[j];
        std::vector<double>& delta = carrier.delta_isobeta[j];
        std::vector<double>& control = carrier.control[j];
        std::vector<int>& cancel = carrier.cancel_isobeta[j];


        Series^ s = gcnew Series(System::String::Format(L"\u03B2 = {0:F2} \u00B0", Convert::ToDouble(carrier.beta_iso[j])));
        s->ChartType = SeriesChartType::Spline;
        s->BorderWidth = 1;
        s->ChartArea = "Main";
        s->Color = Color::FromArgb(255, 255, 255 - intensity, 0);
        s->MarkerStyle = MarkerStyle::Circle;
        s->MarkerSize = 4;

        chart->Series->Add(s);

        for (size_t i = 0; i < x.size(); i++) {
            if (cancel[i] == 1) { continue; }
            int idx = s->Points->AddXY(x[i], y[i]);
            
            
            s->Points[idx]->ToolTip =
                L"\u03B2 = " + carrier.beta_iso[j].ToString("F2") + L" \u00B0"
                L"\n\u03B4d = " + delta[i].ToString("F2") + L" \u00B0" +
                "\nCornering radius = " + R[i].ToString("F2") + " m" +
                "\nVehicle velocity = " + V[i].ToString("F2") + " km/h" +
                "\nLateral acceleration = " + x[i].ToString("F2") + " g" +
                "\nLongitudinal acceleration = " + a_lon[i].ToString("F2") + " g" +
                "\nYaw moment = " + y[i].ToString("F2") + " Nm" +
                "\nControl = " + control[i].ToString("F2") + L" Nm/\u00B0" +
                "\nYaw rate = " + r[i].ToString("F2") + " \u00B0/s";
               
        }
    }

    
    Color base_delta = Color::Blue;
    for (size_t j = 0; j < carrier.a_lat_isodelta.size(); j++) {
        intensity = j * 255 / carrier.a_lat_isodelta.size();

        std::vector<double>& x = carrier.a_lat_isodelta[j];
        std::vector<double>& y = carrier.M_yaw_isodelta[j];
		std::vector<double>& a_lon = carrier.a_lon_isodelta[j];
        std::vector<double>& R = carrier.R_isodelta[j];
        std::vector<double>& V = carrier.V_isodelta[j];
        std::vector<double>& r = carrier.r_isodelta[j];
        std::vector<double>& beta = carrier.beta_isodelta[j];
		std::vector<double>& stability = carrier.stability[j];
        std::vector<int>& cancel = carrier.cancel_isodelta[j];

        Series^ s = gcnew Series(Convert::ToString(System::String::Format(L"\u03B4d = {0:F2} \u00B0", Convert::ToDouble(carrier.delta_iso[j]))));
        s->ChartType = SeriesChartType::Spline;
        s->BorderWidth = 1;
        s->ChartArea = "Main";
        s->Color = Color::FromArgb(255, 0, intensity, 255);
        s->MarkerStyle = MarkerStyle::Circle;
        s->MarkerSize = 4;

        chart->Series->Add(s);

        for (size_t i = 0; i < x.size(); i++) {
			if (cancel[i] == 1) { continue; }
            int idx = s->Points->AddXY(x[i], y[i]);
            
            s->Points[idx]->ToolTip =
                L"\u03B2 = " + beta[i].ToString("F2") + L" \u00B0"
                L"\n\u03B4d = " + carrier.delta_iso[j].ToString("F2") + L" \u00B0" +
                "\nCornering radius = " + R[i].ToString("F2") + " m" +
                "\nVehicle velocity = " + V[i].ToString("F2") + " km/h" +
                "\nLateral acceleration = " + x[i].ToString("F2") + " g" +
                "\nLongitudinal acceleration = " + a_lon[i].ToString("F2") + " g" +
                "\nYaw moment = " + y[i].ToString("F2") + " Nm" +
                "\nStability = " + stability[i].ToString("F2") + L" Nm/\u00B0" +
                "\nYaw rate = " + r[i].ToString("F2") + " \u00B0/s";
                
        }
    }
    
    

    Series^ s = gcnew Series("Single run");
    s->ChartType = SeriesChartType::Point;
    s->BorderWidth = 2;
    s->ChartArea = "Main";
	s->MarkerBorderColor = System::Drawing::Color::Green;
	s->MarkerColor = System::Drawing::Color::Green;
	s->MarkerStyle = MarkerStyle::Star4;
	s->MarkerSize = 10;

    chart->Series->Add(s);

    if (carrier.single_run.cancel == 0) {
        s->Points->AddXY(carrier.single_run.a_lat, carrier.single_run.M_yaw);

        s->Points[0]->ToolTip =
            "Single run simulation:" +
            L"\n\u03B2 = " + carrier.single_run.beta.ToString("F2") + L" \u00B0" +
            L"\n\u03B4d = " + carrier.single_run.delta.ToString("F2") + L" \u00B0" +
            L"\nCornering radius = " + carrier.single_run.R.ToString("F2") + " m" +
            L"\nVehicle velocity = " + carrier.single_run.V.ToString("F2") + " km/h" +
            L"\nLateral acceleration = " + carrier.single_run.a_lat.ToString("F2") + " g" +
            L"\nLongitudinal acceleration = " + carrier.single_run.a_lon.ToString("F2") + " g" +
            L"\nYaw moment = " + carrier.single_run.M_yaw.ToString("F2") + " Nm" +
            L"\nYaw rate = " + carrier.single_run.r.ToString("F2") + " \u00B0/s";
    }
}