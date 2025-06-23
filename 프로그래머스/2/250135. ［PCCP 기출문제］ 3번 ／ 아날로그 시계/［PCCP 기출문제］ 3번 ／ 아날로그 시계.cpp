#include <string>
#include <vector>
#include <iostream>
using namespace std;

void calcArc(double& h_arc, double& m_arc, double& s_arc, int time)
{
    int h = time / 3600;
    int m = (time % 3600) / 60;
    int s = time % 60;
    
    h_arc = (double)(h % 12) * 5.0 + ((double)(time % 3600) * 5.0) / 3600.0;
    m_arc = m + (double)s / 60.0;
    s_arc = (double)s;
}

void Print(int time, double h_arc, double m_arc, double s_arc, int& answer)
{
    cout << time / 3600 << ":" << (time % 3600) / 60 << ":" << time % 60 << endl;
    cout << h_arc << " " << m_arc << " " << s_arc << endl << endl;
    answer++;
}


int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    int h = h1;
    int m = m1;
    int s = s1;
    
    int time = h * 3600 + m * 60 + s;
    int end_time = h2 * 3600 + m2 * 60 + s2;
    
    double h_arc, m_arc, s_arc;    
    double ph_arc, pm_arc, ps_arc;
    calcArc(ph_arc, pm_arc, ps_arc, time);
    if (ph_arc == ps_arc || pm_arc == ps_arc) Print(time, h_arc, m_arc, s_arc, answer);
    while (time < end_time)
    {
        time++;
        calcArc(h_arc, m_arc, s_arc, time);
        
        if (s_arc == 0.0)
        {
            s_arc = 60;
            if (h_arc == 0.0) h_arc = 60.0;
            if (m_arc == 0.0) m_arc = 60.0;
            
            if (ph_arc > s_arc - 1.0 && h_arc <= s_arc) 
            {
                answer++;
            }
            if (pm_arc > s_arc - 1.0 && m_arc <= s_arc)
            {
                if (s_arc == m_arc && s_arc == h_arc) answer--;
                answer++;
            }
            
            if (h_arc == 60.0) h_arc = 0.0;
            if (s_arc == 60.0) s_arc = 0.0;
        }
        else
        {
            if (ph_arc > s_arc - 1.0 && h_arc <= s_arc) answer++;
            if (pm_arc > s_arc - 1.0 && m_arc <= s_arc)
            {
                answer++;
                if (s_arc == 1.0) answer--;
            }
        }
        ph_arc = h_arc;
        pm_arc = m_arc;
    }
    
    return answer;
}