const config = {
    //作者名字
    author: 'Creazing',
    title: '優萌初華',
    description: '= 有夢書架 =',
    // 导航栏
    nav: [
        { name: 'Creazing', link: "/", children: [], liClass: 'title', rel: 'start', iClass: '', aClass: '' },
        { name: '首页', link: "/", children: [], liClass: 'active', rel: 'section', iClass: 'i-home', aClass: '' },
        { name: '关于', link: "/about/", children: [{ name: '自设', link: "/about/yume", children: [], liClass: '', rel: 'section', iClass: 'i-cloud' }], liClass: 'dropdown', rel: 'section', iClass: 'i-user', aClass: '' },
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
    ],
    sidebar: {
        avator: '//cdn.jsdelivr.net/gh/amehime/shoka@30732f13/images/avatar.jpg',
        author: 'Creazing',
        description: 'xxxx',
        articlesNum: '11',
        categoriesNum: '22',
        tagsNum: '33',
        socialLinks: [
            { url: 'https://github.com/amehime', name: 'github', icon: "i-github" },
            { url: 'https://twitter.com/amehime', name: 'twitter', icon: "i-twitter" },
            { url: 'https://www.zhihu.com/people/amehime', name: 'zhihu', icon: "i-zhihu" },
            { url: 'https://music.163.com/#/user/home?id=12886823', name: 'music', icon: "i-cloud-music" },
            { url: 'https://t.me/amehime', name: 'telegram', icon: "i-paper-plane" },
            { url: 'https://about.me/amehime', name: 'about', icon: "i-address-card" },
        ]
    }
}
export default config