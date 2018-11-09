using System;
using System.Configuration;
using Newtonsoft.Json;
using System.Net.Http;
using System.Collections.Generic;

namespace SmartSeat.Models
{
    public class DweetService
    {
        public class Content
        {
            public string value { get; set; }
        }

        public class With
        {
            public string thing { get; set; }
            public DateTime created { get; set; }
            public Content content { get; set; }
        }

        public class JsonDweet
        {
            public string @this { get; set; }
            public string by { get; set; }
            public string the { get; set; }
            public List<With> with { get; set; }
        }

        public static JsonDweet checkDweetValue()
        {
            string url = ConfigurationManager.AppSettings["UrlDweet"];
            StringContent Content = new StringContent("application/json");
            using (var client = new HttpClient())
            {
                HttpResponseMessage Response = client.GetAsync(url).Result;
                string str = Response.Content.ReadAsStringAsync().Result;
                Console.WriteLine(Response.StatusCode);
                JsonDweet returnObject = JsonConvert.DeserializeObject<JsonDweet>(str);
                return returnObject;
            }
        }
    }
}