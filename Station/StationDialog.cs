using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Station
{
    public static class StationDialog
    {
        public static StationModel GetStation()
        {
            var dialog = new Dialog();
            if (dialog.IsEnable) dialog.ShowDialog();
       
            return dialog.Station;
        }
    }
}
