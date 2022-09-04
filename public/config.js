const config = {
    //作者名字
    author: 'Creazing',
    // 导航栏
    nav: [
        { name: 'Creazing', link: "/", children: [], liClass: 'title', rel: 'start', iClass: '', aClass: '' },
        { name: '首页', link: "/", children: [], liClass: 'active', rel: 'section', iClass: 'i-home', aClass: '' },
        { name: '关于', link: "/about/", children: [{ name: '自设', link: "/about/yume", children: [], liClass: '', rel: 'section', iClass: 'i-cloud' }], liClass: 'dropdown', rel: 'section', iClass: 'i-use', aClass: '' },
        {
            name: '文章', link: "#", children: [
                { name: '归档', link: "/archives/", children: [], liClass: '', rel: 'section', iClass: 'i-list-alt', aClass: '' },
                { name: '分类', link: "/categories", children: [], liClass: '', rel: 'section', iClass: 'i-th', aClass: '' },
                { name: '标签', link: "/tags", children: [], liClass: '', rel: 'section', iClass: 'i-tags', aClass: '' },
            ], liClass: 'dropdown', rel: '', iClass: 'i-feather', aClass: ''
        },

        {
            name: '链环', link: "#", children: [
                { name: '友達', link: "/friends/", children: [], liClass: '', rel: 'section', iClass: 'i-heart', aClass: '' },
                { name: '网址', link: "/webstack/", children: [], liClass: '', rel: 'section', iClass: 'i-star', aClass: '' },
            ], liClass: 'dropdown', rel: '', iClass: 'i-magic', aClass: ''
        },
        { name: '开往', link: "#", children: [], liClass: '', rel: 'noopener external nofollow noreferrer', iClass: 'i-paper-plane', aClass: 'exturl' }
    ]
}
export default config