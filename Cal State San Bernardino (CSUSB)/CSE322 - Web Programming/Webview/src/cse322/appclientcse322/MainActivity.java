package cse322.appclientcse322;



import android.app.Activity;
import android.os.Bundle;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

/**
 * Generic code for HTML5-based Android applications.
 * 
 * See http://developer.android.com/guide/webapps/webview.html
 */
public class MainActivity extends Activity
{
    private final String appServer = "http://jscsusbmobile.appspot.com/";

    @Override
    public void onCreate(Bundle savedInstanceState) 
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        WebView webView = (WebView) findViewById(R.id.webview);
        WebSettings webSettings = webView.getSettings();
        webSettings.setJavaScriptEnabled(true);
        webView.setWebViewClient(new WebViewClient());
        webView.loadUrl(appServer);
    }
}