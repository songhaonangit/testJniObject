package com.getcharmsmart.testjniobject;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import java.nio.charset.StandardCharsets;

public class MainActivity extends AppCompatActivity {
    static{
        System.loadLibrary("qx-native-lib");
    }
    private native test_data call(test_data data);
    private test_data data = new test_data();
    private static final String TAG="MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        data = call(data);
        Log.e(TAG, "name:" + data.name);
        Log.e(TAG, "num:" + data.num);
        Log.e(TAG, "average:" + data.average);
        Log.e(TAG, "revb:" + data.revb);
        Log.e(TAG,""+data.text.length);

        for(int i =0;i<6;i++){
            Log.e(TAG, "text:" +i+"---"+data.text[i]);
        }
    }
}
