<template>
  <div id="sidebar" class style>
    <div class="inner">
      <ul class="tab">
        <li class="contents item active">
          <span>文章目录</span>
        </li>
        <li class="related item">
          <span>系列文章</span>
        </li>
        <li class="overview item">
          <span>站点概览</span>
        </li>
      </ul>
      <div class="panels" style="height: 953px;">
        <div class="inner">
          <div class="contents panel pjax active" data-title="文章目录">
            <ol class="toc">
              <li class="toc-item toc-level-1 active current">
                <a class="toc-link" href="#%E8%AE%BE%E8%AE%A1%E7%BC%98%E7%94%B1">
                  <span class="toc-number">1.</span>
                  <span class="toc-text">设计缘由</span>
                </a>
              </li>
              <li class="toc-item toc-level-1">
                <a class="toc-link" href="#%E5%BF%AB%E9%80%9F%E5%AE%89%E8%A3%85">
                  <span class="toc-number">2.</span>
                  <span class="toc-text">快速安装</span>
                </a>
              </li>
              <li class="toc-item toc-level-1">
                <a class="toc-link" href="#%E5%AE%89%E8%A3%85%E4%BE%9D%E8%B5%96%E6%8F%92%E4%BB%B6">
                  <span class="toc-number">3.</span>
                  <span class="toc-text">安装依赖插件</span>
                </a>
              </li>
              <li class="toc-item toc-level-1">
                <a class="toc-link" href="#%E5%BA%94%E7%94%A8%E4%B8%BB%E9%A2%98">
                  <span class="toc-number">4.</span>
                  <span class="toc-text">应用主题</span>
                </a>
                <ol class="toc-child">
                  <li class="toc-item toc-level-2">
                    <a
                      class="toc-link"
                      href="#%E4%BF%AE%E6%94%B9%E7%AB%99%E7%82%B9%E9%85%8D%E7%BD%AE"
                    >
                      <span class="toc-number">4.1.</span>
                      <span class="toc-text">修改站点配置</span>
                    </a>
                  </li>
                  <li class="toc-item toc-level-2">
                    <a
                      class="toc-link"
                      href="#%E4%BF%AE%E6%94%B9%E4%B8%BB%E9%A2%98%E9%85%8D%E7%BD%AE"
                    >
                      <span class="toc-number">4.2.</span>
                      <span class="toc-text">修改主题配置</span>
                    </a>
                  </li>
                </ol>
              </li>
              <li class="toc-item toc-level-1">
                <a class="toc-link" href="#%E6%9B%B4%E6%96%B0%E8%AE%B0%E5%BD%95">
                  <span class="toc-number">5.</span>
                  <span class="toc-text">更新记录</span>
                </a>
                <ol class="toc-child">
                  <li class="toc-item toc-level-2">
                    <a class="toc-link" href="#024-025">
                      <span class="toc-number">5.1.</span>
                      <span class="toc-text">0.2.4 👉 0.2.5</span>
                    </a>
                  </li>
                  <li class="toc-item toc-level-2">
                    <a class="toc-link" href="#023-024">
                      <span class="toc-number">5.2.</span>
                      <span class="toc-text">0.2.3 👉 0.2.4</span>
                    </a>
                  </li>
                  <li class="toc-item toc-level-2">
                    <a class="toc-link" href="#022-023">
                      <span class="toc-number">5.3.</span>
                      <span class="toc-text">0.2.2 👉 0.2.3</span>
                    </a>
                  </li>
                  <li class="toc-item toc-level-2">
                    <a class="toc-link" href="#021-022">
                      <span class="toc-number">5.4.</span>
                      <span class="toc-text">0.2.1 👉 0.2.2</span>
                    </a>
                  </li>
                  <li class="toc-item toc-level-2">
                    <a class="toc-link" href="#02-021">
                      <span class="toc-number">5.5.</span>
                      <span class="toc-text">0.2 👉 0.2.1</span>
                    </a>
                  </li>
                  <li class="toc-item toc-level-2">
                    <a class="toc-link" href="#019-02">
                      <span class="toc-number">5.6.</span>
                      <span class="toc-text">0.1.9 👉 0.2</span>
                    </a>
                  </li>
                </ol>
              </li>
            </ol>
          </div>
          <div class="related panel pjax" data-title="系列文章">
            <ul>
              <li class="active">
                <a
                  href="/computer-science/note/theme-shoka-doc/"
                  rel="bookmark"
                  title="Hexo主题Shoka &amp; multi-markdown-it渲染器使用说明"
                >Hexo主题Shoka &amp; multi-markdown-it渲染器使用说明</a>
              </li>
              <li>
                <a
                  href="/computer-science/note/theme-shoka-doc/dependents/"
                  rel="bookmark"
                  title="Step.1 依赖插件"
                >Step.1 依赖插件</a>
              </li>
              <li>
                <a
                  href="/computer-science/note/theme-shoka-doc/config/"
                  rel="bookmark"
                  title="Step.2 基本配置"
                >Step.2 基本配置</a>
              </li>
              <li>
                <a
                  href="/computer-science/note/theme-shoka-doc/display/"
                  rel="bookmark"
                  title="Step.3 界面显示"
                >Step.3 界面显示</a>
              </li>
              <li>
                <a
                  href="/computer-science/note/theme-shoka-doc/special/"
                  rel="bookmark"
                  title="Step.4 主题特殊功能"
                >Step.4 主题特殊功能</a>
              </li>
            </ul>
          </div>
          <div class="overview panel" data-title="站点概览">
            <div class="author" itemprop="author" itemscope itemtype="http://schema.org/Person">
              <img
                class="image lozaded"
                itemprop="image"
                alt="Ruri Shimotsuki"
                data-src="//cdn.jsdelivr.net/gh//shoka@30732f13/images/avatar.jpg"
                src="//cdn.jsdelivr.net/gh//shoka@30732f13/images/avatar.jpg"
                data-loaded="true"
              />
              <p class="name" itemprop="name">Ruri Shimotsuki</p>
              <div class="description" itemprop="description">琉璃的医学 &amp; 编程笔记</div>
            </div>
            <nav class="state">
              <div class="item posts">
                <a href="/archives/">
                  <span class="count">216</span>
                  <span class="name">文章</span>
                </a>
              </div>
              <div class="item categories">
                <a href="/categories/">
                  <span class="count">48</span>
                  <span class="name">分类</span>
                </a>
              </div>
              <div class="item tags">
                <a href="/tags/" class="warning">
                  <span class="count">71</span>
                  <span class="name">标签</span>
                </a>
              </div>
            </nav>
            <div class="social">
              <a
                href="https://github.com/"
                rel="noopener external nofollow noreferrer"
                target="_blank"
                class="exturl item github"
                title="https://github.com/"
              >
                <i class="ic i-github"></i>
              </a>
              <a
                href="https://twitter.com/"
                rel="noopener external nofollow noreferrer"
                target="_blank"
                class="exturl item twitter"
                title="https://twitter.com/"
              >
                <i class="ic i-twitter"></i>
              </a>
              <a
                href="https://www.zhihu.com/people/"
                rel="noopener external nofollow noreferrer"
                target="_blank"
                class="exturl item zhihu"
                title="https://www.zhihu.com/people/"
              >
                <i class="ic i-zhihu"></i>
              </a>
              <a
                href="https://music.163.com/#/user/home?id=12886823"
                rel="noopener external nofollow noreferrer"
                target="_blank"
                class="exturl item music"
                title="https://music.163.com/#/user/home?id=12886823"
              >
                <i class="ic i-cloud-music"></i>
              </a>
              <a
                href="https://t.me/"
                rel="noopener external nofollow noreferrer"
                target="_blank"
                class="exturl item telegram"
                title="https://t.me/"
              >
                <i class="ic i-paper-plane"></i>
              </a>
              <a
                href="https://about.me/"
                rel="noopener external nofollow noreferrer"
                target="_blank"
                class="exturl item about"
                title="https://about.me/"
              >
                <i class="ic i-address-card"></i>
              </a>
            </div>
            <ul class="menu">
              <li class="item">
                <a href="/" rel="section">
                  <i class="ic i-home"></i>首页
                </a>
              </li>
              <li class="item dropdown">
                <a href="/about/" rel="section">
                  <i class="ic i-user"></i>关于
                </a>
                <ul class="submenu">
                  <li class="item">
                    <a href="/about/yume" rel="section">
                      <i class="ic i-cloud"></i>自设
                    </a>
                  </li>
                </ul>
              </li>
              <li class="item dropdown">
                <a href="javascript:void(0);">
                  <i class="ic i-feather"></i>文章
                </a>
                <ul class="submenu">
                  <li class="item">
                    <a href="/archives/" rel="section">
                      <i class="ic i-list-alt"></i>归档
                    </a>
                  </li>
                  <li class="item">
                    <a href="/categories/" rel="section">
                      <i class="ic i-th"></i>分类
                    </a>
                  </li>
                  <li class="item">
                    <a href="/tags/" rel="section">
                      <i class="ic i-tags"></i>标签
                    </a>
                  </li>
                </ul>
              </li>
              <li class="item dropdown">
                <a href="javascript:void(0);">
                  <i class="ic i-magic"></i>链环
                </a>
                <ul class="submenu">
                  <li class="item">
                    <a href="/friends/" rel="section">
                      <i class="ic i-heart"></i>友達
                    </a>
                  </li>
                  <li class="item">
                    <a href="/webstack/" rel="section">
                      <i class="ic i-star"></i>网址
                    </a>
                  </li>
                </ul>
              </li>
              <li class="item">
                <a
                  href="https://travellings.link"
                  rel="noopener external nofollow noreferrer"
                  target="_blank"
                  class="exturl"
                  title="开往"
                >
                  <i class="ic i-paper-plane"></i>开往
                </a>
              </li>
            </ul>
          </div>
        </div>
      </div>
      <ul id="quick">
        <li class="prev pjax">
          <a
            href="/inter-discipline/health-informatics/specialization-1/course-1/week-1/"
            rel="prev"
            title="上一篇"
          >
            <i class="ic i-chevron-left"></i>
          </a>
        </li>
        <li class="up">
          <i class="ic i-arrow-up"></i>
        </li>
        <li class="down">
          <i class="ic i-arrow-down"></i>
        </li>
        <li class="next pjax">
          <a href="/computer-science/note/theme-shoka-doc/dependents/" rel="next" title="下一篇">
            <i class="ic i-chevron-right"></i>
          </a>
        </li>
        <li class="percent" style="width: 0%;"></li>
      </ul>
    </div>
  </div>
</template>