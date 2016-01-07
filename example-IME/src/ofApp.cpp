#include "ofApp.h"

string ofLocaleToUtf8(const string & locale)
{
	int size = MultiByteToWideChar(CP_THREAD_ACP, // code page
		MB_ERR_INVALID_CHARS, // character-type options
		locale.c_str(), // address of string to map
		-1, // NULL terminated
		NULL, // address of wide-character buffer
		0) + 1;               // size of buffer


	WCHAR * pWideChar = new WCHAR[size];

	MultiByteToWideChar(CP_THREAD_ACP, // code page
		MB_ERR_INVALID_CHARS, // character-type options
		locale.c_str(), // address of string to map
		-1, // NULL terminated
		pWideChar, // address of wide-character buffer
		size);                // size of buffer

	size = WideCharToMultiByte(CP_UTF8, // code page
		0, // performance and mapping flags
		pWideChar, // address of wide-character string
		-1, // NULL terminated
		NULL, // address of buffer for new string
		0, // size of buffer
		NULL, // address of default for unmappable characters
		NULL) + 1; // address of flag set when default char used

	char * pUtf8 = new char[size];

	WideCharToMultiByte(CP_UTF8, // code page
		0, // address of wide-character string
		pWideChar, // address of wide-character string
		-1, // NULL terminated
		pUtf8, // address of buffer for new string
		size, // size of buffer
		NULL, // address of default for unmappable characters
		NULL);     // address of flag set when default char used

	string Utf8 = pUtf8;

	delete[] pWideChar;
	delete[] pUtf8;

	return Utf8;
}

char buf[256];

#include "ofAppGLFWWindow.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	// add font should before gui.setup() otherwise font will not build
	ImGuiIO * io = &ImGui::GetIO();
	ImFontConfig font_config; font_config.OversampleH = 1; font_config.OversampleV = 1; font_config.PixelSnapH = 1;
	io->Fonts->AddFontFromFileTTF("data/Deng.ttf", 18.0f, &font_config, io->Fonts->GetGlyphRangesChinese());

	gui.setup();

	ImGui::GetIO().MouseDrawCursor = false;

	// For Microsoft IME, pass your HWND to enable IME positioning:
	io->ImeWindowHandle = ofGetWin32Window();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	gui.begin();

	{
		ImGuiIO& io = ImGui::GetIO();

		// translate text from wstring to utf8
		wstring wstr = L"中文显示";
		string txt;
		utf8::utf16to8(wstr.begin(), wstr.end(), back_inserter(txt));
		ImGui::Text(txt.c_str());

		// translate locale string to utf8
		ImGui::InputText(ofLocaleToUtf8("输入中文").c_str(), buf, 256);

		if (ImGui::Button(ofLocaleToUtf8("帮助窗口").c_str()))
		{
			show_test_window = !show_test_window;
		}
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}

	if (show_test_window)
	{
		ImGui::SetNextWindowPos(ofVec2f(650, 20), ImGuiSetCond_FirstUseEver);
		ImGui::ShowTestWindow(&show_test_window);
	}

	gui.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
