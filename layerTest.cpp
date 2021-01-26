#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
class LayerStack {
	private:
	std::vector<int> m_Layers;
	std::vector<int> m_Overlays;
	public:
	LayerStack();
	~LayerStack();

	void PushLayer(int layer);
	void PushOverLay(int overlay);
	void PopLayer(int layer);
	void PopOverlay(int overlay);
    template<class T>
    void Iterate(T fn);
};
LayerStack::LayerStack() {
}

LayerStack::~LayerStack() {
}
template<class T>
void LayerStack::Iterate(T fn){
    std::vector<int>::iterator ptr = m_Overlays.end();
    while(ptr != m_Overlays.begin())
        fn(*(--ptr));
    ptr = m_Layers.end();
    while(ptr != m_Layers.begin())
        fn(*(--ptr));
}
//Pushed as last layer
void LayerStack::PushLayer(int layer) {
    m_Layers.emplace_back(layer);
}
void LayerStack::PushOverLay(int overlay) {
	m_Overlays.emplace_back(overlay);
}
void LayerStack::PopLayer(int layer) {
	auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
	if (it != m_Layers.end())
		m_Layers.erase(it);
}
void LayerStack::PopOverlay(int overlay) {
	auto it = std::find(m_Overlays.begin(), m_Overlays.end(), overlay);
	if (it != m_Overlays.end())
		m_Overlays.erase(it);
}
int main(){
    LayerStack st;
    st.PushLayer(3);
    st.PushLayer(7);
    st.PushLayer(9);
    st.PushLayer(1);
    st.PopLayer(7);
    st.PushOverLay(18);
    st.PushOverLay(12);
    // st.PopOverlay(18);
    // st.PopOverlay(12);
    st.PushLayer(11);
    st.Iterate([](int i){std::cout << i << " ";});
    return 0;
}