using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Xml;
using System.Xml.Serialization;

namespace Station
{
    /// <summary>
    /// Dialog.xaml 的交互逻辑
    /// </summary>
    public partial class Dialog : Window
    {
        private static Dictionary<int, StationModel> _stations;
        public StationModel Station;
        public bool IsEnable = true;

        public Dialog()
        {
            if (_stations == null) _stations = ReadStations();
            if (_stations == null)
            {
                MessageBox.Show("站点数据顺坏！");
                IsEnable = false;
                Close();
            }
            Station = null;
            InitializeComponent();
        }

        public StationModel GetStation()
        {
            ShowDialog();
            return Station;
        }

        private void Station_Click(object sender, RoutedEventArgs e)
        {
            var stationNo = int.Parse((sender as Button).Tag as string);
            if (_stations.Keys.Contains(stationNo)) Station = _stations[stationNo];
            Close();
        }

        private Dictionary<int, StationModel> ReadStations()
        {
            var stationList = ReadXml<List<StationModel>>("stations.xml");
            return stationList?.ToDictionary(s => s.No);
        }

        public T ReadXml<T>(string xmlPath)
        {
            try
            {
                if (File.Exists(xmlPath))
                {
                    using (XmlReader reader = XmlReader.Create(xmlPath))
                    {
                        XmlSerializer xz = new XmlSerializer(typeof(T));
                        return (T)xz.Deserialize(reader);
                    }
                }
            }
            catch { }
            return default(T);
        }

        private void WriteXml(object obj, string xmlPath)
        {
            XmlDocument xd = new XmlDocument();
            using (StringWriter sw = new StringWriter())
            {
                XmlSerializer xz = new XmlSerializer(obj.GetType());
                xz.Serialize(sw, obj);
                xd.LoadXml(sw.ToString());
                xd.Save(xmlPath);
            }
        }

        private void InitStation()
        {
            var stations = new List<StationModel>();
            stations.Add(new StationModel()
            {
                No = 1,
                Name = "北京西站",
                Longitude = 116.315139,
                Latitude = 39.893449
            });
            WriteXml(stations, "stations.xml");
        }
    }
}
