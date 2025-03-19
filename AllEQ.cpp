#include <gtkmm.h>
#include <vector>

class EqualizerWindow : public Gtk::Window {
    public:
        EqualizerWindow();
    
    private:
        Gtk::Box main_box{Gtk::ORIENTATION_VERTICAL, 5};
        Gtk::Box sliders_box{Gtk::ORIENTATION_HORIZONTAL, 5};
        Gtk::ComboBoxText preset_selector;
        Gtk::ComboBoxText profile_selector;
        Gtk::Button apply_button{"Apply"};
        Gtk::Button save_profile_button{"Save Profile"};
        std::vector<Gtk::Scale> sliders;
        std::map<std::string, std::vector<double>> profiles;
        
        void on_preset_changed();
        void on_apply_clicked();
        void on_save_profile();
        void snap_bands();
    };

EqualizerWindow::EqualizerWindow() {
    set_title("AllEQ");
    set_default_size(400, 300);
    add(main_box);
    
    preset_selector.append("Flat");
    preset_selector.append("Classical");
    preset_selector.append("Dance");
    preset_selector.append("Blues");
    preset_selector.append("Country");
    preset_selector.append("Folk");
    preset_selector.append("Hip-Hop");
    preset_selector.append("Metal");
    preset_selector.append("R&B");
    preset_selector.append("Reggae");
    preset_selector.append("Soul");
    preset_selector.append("Techno");
    preset_selector.append("Rap");
    preset_selector.append("Electronic");
    preset_selector.append("Indie");
    preset_selector.append("Funk");
    preset_selector.append("Gospel");
    preset_selector.append("Punk");
    preset_selector.append("Ska");
    preset_selector.append("Old School");
    preset_selector.append("New Age");
    preset_selector.append("Alternative");
    preset_selector.append("Blues-Rock");
    preset_selector.append("Hard Rock");
    preset_selector.append("Metal");
    preset_selector.append("Punk Rock");
    preset_selector.append("Heavy Metal");
    preset_selector.append("Grunge");
    preset_selector.append("Jazz Rock");
    preset_selector.append("Pop Rock");
    preset_selector.append("Progressive Rock");
    preset_selector.append("Rock 'n' Roll");
    preset_selector.append("Jazz");
    preset_selector.append("Pop");
    preset_selector.set_active(0);
    preset_selector.signal_changed().connect(sigc::mem_fun(*this, &EqualizerWindow::on_preset_changed));
    main_box.pack_start(preset_selector, Gtk::PACK_SHRINK);
    
     profile_selector.append("Default");
     profile_selector.set_active(0);
     main_box.pack_start(profile_selector, Gtk::PACK_SHRINK);
     
     for (int i = 0; i < 10; ++i) {
         sliders.emplace_back(Gtk::ORIENTATION_VERTICAL);
         sliders.back().set_range(-12.0, 12.0);
         sliders.back().set_value(0.0);
         sliders.back().signal_value_changed().connect(sigc::mem_fun(*this, &EqualizerWindow::snap_bands));
         sliders_box.pack_start(sliders.back(), Gtk::PACK_EXPAND_WIDGET);
     }
     main_box.pack_start(sliders_box, Gtk::PACK_EXPAND_WIDGET);
     
     apply_button.signal_clicked().connect(sigc::mem_fun(*this, &EqualizerWindow::on_apply_clicked));
     main_box.pack_start(apply_button, Gtk::PACK_SHRINK);
     
     save_profile_button.signal_clicked().connect(sigc::mem_fun(*this, &EqualizerWindow::on_save_profile));
     main_box.pack_start(save_profile_button, Gtk::PACK_SHRINK);
     
     show_all_children();
 }

void EqualizerWindow::on_preset_changed() {
    std::string preset = preset_selector.get_active_text();
    std::vector<double> values;
    
    if (preset == "Flat") {
        values = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    } else if (preset == "Rock") {
        values = {-5, -3, 0, 3, 5, 5, 3, 0, -3, -5};
    } else if (preset == "Jazz") {
        values = {3, 2, 0, -2, -3, -3, -2, 0, 2, 3};
    } else if (preset == "Pop") {
        values = {-2, -1, 1, 3, 4, 4, 3, 1, -1, -2};
    }
    if (preset == "Classical") {
        values = {-10, -5, 0, 5, 10, 10, 5, 0, -5, -10};
    }
    else if (preset == "Dance") {
        values = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    }
    else if (preset == "Blues") {
        values = {-8, -6, 0, 6, 8, 8, 6, 0, -6, -8};
    }
    else if (preset == "Country") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Folk") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Hip-Hop") {
        values = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    }
    else if (preset == "Metal") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "R&B") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Reggae") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Soul") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Techno") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Rap") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Electronic") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Indie") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Funk") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Gospel") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Punk") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Ska") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Old School") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "New Age") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Alternative") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Blues-Rock") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Hard Rock") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Metal") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Punk Rock") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Heavy Metal") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Grunge") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Jazz Rock") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Pop Rock") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Progressive Rock") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Rock 'n' Roll") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    else if (preset == "Jazz") {
        values = {3, 2, 0, -2, -3, -3, -2, 0, 2, 3};
    }
    else if (preset == "Pop") {
        values = {-10, -8, 0, 8, 10, 10, 8, 0, -8, -10};
    }
    for (size_t i = 0; i < sliders.size(); ++i) {
        sliders[i].set_value(values[i]);
    }
}

void EqualizerWindow::on_apply_clicked() {
    std::cout << "Equalizer settings applied:\n";
    for (size_t i = 0; i < sliders.size(); ++i) {
        std::cout << "Band " << i + 1 << ": " << sliders[i].get_value() << " dB\n";
    }
}

void EqualizerWindow::on_save_profile() {
    std::string profile_name = "Profile " + std::to_string(profiles.size() + 1);
    std::vector<double> values;
    for (auto& slider : sliders) {
        values.push_back(slider.get_value());
    }
    profiles[profile_name] = values;
    profile_selector.append(profile_name);
    profile_selector.set_active_text(profile_name);
    std::cout << "Profile saved: " << profile_name << "\n";
}

void EqualizerWindow::snap_bands() {
    for (auto& slider : sliders) {
        double value = slider.get_value();
        double snapped_value = round(value);
        slider.set_value(snapped_value);
    }
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "com.example.equalizer");
    EqualizerWindow window;
    return app->run(window);
}
