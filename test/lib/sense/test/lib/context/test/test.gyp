{
	'includes':[
		'lib/context/def.gypi',
		'plank/def/mac-targets.gypi',
		'plank/def/cpp11.gypi'
	],#inclues
	'target_defaults': {
		'target_name': 'test', 
		'type': 'executable',
		'sources': [
			'src/main.cpp',
			'src/context_test.h'
		], #sources
		'include_dirs': [
			'plank/src/',
			'.'
		], #include_dirs		
	}, #target_defaults
}