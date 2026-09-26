from pathlib import Path
r=Path(__file__).resolve().parents[1]
p=r/'renderer008/live_frame.h';s=p.read_text().replace('bool ready{},hidden{};','const uint8_t* fixture_source{};\n size_t fixture_size{};\n bool ready{},hidden{};').replace('child_head=0;}','child_head=0;fixture_source=nullptr;fixture_size=0;}');p.write_text(s)
p=r/'renderer008/live_frame.cpp';s=p.read_text().replace('resident.ready=true;++resident.restores;', 'resident.ready=true;resident.fixture_source=f.bytes;resident.fixture_size=f.size;++resident.restores;').replace('resident.root.record < f.bytes || resident.root.record >= f.bytes+f.size','resident.fixture_source!=f.bytes || resident.fixture_size!=f.size');p.write_text(s)
p=r/'renderer008/host_frame.cpp';s=p.read_text().replace('  std::printf("PASS: poisoned output', '''  // A resident object must not be silently reused with another input owner.
  auto other=inputs; tree::Fixtures other_fixture;
  if(tree::parse(other.data(),other.size(),other_fixture)!=tree::FixtureError::ok)return 10;
  auto wrong_owner=scene008::frame(other_fixture,*work,scene,*resident,false);
  if(wrong_owner.error!=8 || resident->frames!=4)return 11;
  auto invalid_capacity=scene008::frame(f,*work,scene,*resident,false,nullptr,1);
  if(invalid_capacity.error!=1 || resident->frames!=4)return 12;
  // Corrupt the reference output only, never the original input machine state.
  // The bridge must reject it; there is no route to copy reference vertices.
  tree::Case first;
  if(tree::get(other_fixture,0,first)!=tree::FixtureError::ok||!first.draws)return 13;
  other[size_t(first.expected-other.data())+80]^=1;
  auto bad_resident=std::make_unique<scene008::Resident>();
  std::memset(scene.writable_vertices(),0xa5,sizeof(replay::GpuVertex)*6*scene.draw_count());
  auto corrupt_oracle=scene008::frame(other_fixture,*work,scene,*bad_resident,false);
  if(corrupt_oracle.error!=21 || corrupt_oracle.draws!=0 || corrupt_oracle.matches!=0)return 14;
  std::printf("PASS: wrong fixture ownership, invalid output capacity and corrupt oracle explicitly rejected.\\n");
  std::printf("PASS: poisoned output''');p.write_text(s)
p=r/'renderer008/CMakeLists.txt';s=p.read_text()+'''\ntarget_compile_options(cc_scene_fused PRIVATE -Wall -Wextra -Werror -ffp-contract=off -fno-fast-math)
add_executable(cc_fixture_tests ../runtime008/fixture_tests.cpp)
target_link_libraries(cc_fixture_tests PRIVATE cc_tree)
enable_testing()
add_test(NAME tree_fixture_guards COMMAND cc_fixture_tests ${CMAKE_CURRENT_SOURCE_DIR}/menu.cct ${CMAKE_CURRENT_SOURCE_DIR}/book.cct)
add_test(NAME original_tree_soft_fma COMMAND cc_tree_tests_soft ${CMAKE_CURRENT_SOURCE_DIR}/menu.cct ${CMAKE_CURRENT_SOURCE_DIR}/book.cct)
''';p.write_text(s)
